
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* TODO(eteran): define constants for orientation */

/**
 * @brief Write a single character to a stream (thread-unsafe)
 *
 * @param c the character to write
 * @param stream the stream to write to
 * @return int the character written, or EOF on error
 */
int __elibc_fputc(int c, FILE *stream, int wide) {

	/* TODO(eteran): set stream.err on error */

	const unsigned char ch = (unsigned char)c;
	int r;

	assert(stream);

	assert(_FDATA(stream)->orientation_set == 0 || _FDATA(stream)->orientation_wide == wide);

	_FDATA(stream)->orientation_set  = 1;
	_FDATA(stream)->orientation_wide = wide;

	if (!_FDATA(stream)->buffer_start) {
		_ELIBC_ALLOCATE_FILE_BUFFER(stream);
	}

	/* this is only true after a read into the buffer */

	switch (_FDATA(stream)->buf_mode) {
	case _IOFBF:
		*_FDATA(stream)->buffer_first++ = (char)ch;
		if (_FDATA(stream)->buffer_first == _FDATA(stream)->buffer_end) {
			r = __elibc_fflush(stream) == 0 ? c : EOF;
		} else {
			r = c;
		}
		break;

	case _IOLBF:
		*_FDATA(stream)->buffer_first++ = (char)ch;
		if (ch == '\n' || (_FDATA(stream)->buffer_first == _FDATA(stream)->buffer_end)) {
			r = __elibc_fflush(stream) == 0 ? c : EOF;
		} else {
			r = c;
		}
		break;

	case _IONBF:
		r = (__elibc_sys_write(_ELIBC_FILENO(stream), &ch, 1) == 1) ? c : EOF;
		break;

	default:
		r = c;
		break;
	}

	return r;
}

/**
 * @brief Write a single character to a stream
 *
 * @param c the character to write
 * @param stream the stream to write to
 * @return int the character written, or EOF on error
 */
int fputc(int c, FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_fputc(c, stream, _ELIBC_FILE_NARROW), &r);
	return r;
}
