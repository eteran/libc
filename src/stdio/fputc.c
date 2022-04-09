
#define __ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fputc
// Desc: writes a single byte into a character stream
//       returns 0 on success and -1 on error
//----------------------------------------------------------------------------*/
int __elibc_fputc(int c, FILE *stream, int orientation) {

	/* TODO(eteran): set stream.err on error */

	const unsigned char ch = (unsigned char)c;
	int r;

	assert(stream);
	assert(_FDATA(stream)->orientation != (orientation ^ 0x01));

	_FDATA(stream)->orientation = orientation;

	if (!_FDATA(stream)->buffer_ptr) {
		char *const buffer = malloc(BUFSIZ);
		_FDATA(stream)->buffer_ptr = buffer;
		_FDATA(stream)->buffer_first = buffer;
		_FDATA(stream)->buffer_last = buffer;
		_FDATA(stream)->buffer_capacity = BUFSIZ;

		/* record this so we can free it */
		_FDATA(stream)->internal_buffer_ptr = buffer;
	}

	/* this is only true after a read into the buffer */

	switch (_FDATA(stream)->buf_mod) {
	case _IOFBF:
		*_FDATA(stream)->buffer_first++ = ch;
		if (_FDATA(stream)->buffer_first ==
		    _FDATA(stream)->buffer_ptr + _FDATA(stream)->buffer_capacity) {
			r = __elibc_fflush(stream) == 0 ? 0 : -1;
		} else {
			r = 0;
		}
		break;

	case _IOLBF:
		*_FDATA(stream)->buffer_first++ = ch;
		if (ch == '\n' || (_FDATA(stream)->buffer_first ==
		                   _FDATA(stream)->buffer_ptr + _FDATA(stream)->buffer_capacity)) {
			r = __elibc_fflush(stream) == 0 ? 0 : -1;
		} else {
			r = 0;
		}
		break;

	case _IONBF:
		r = (__elibc_sys_write(__ELIBC_FILENO(stream), &ch, 1) == 1) ? 0 : -1;
		break;

	default:
		r = 0;
		break;
	}

	return r;
}

/*------------------------------------------------------------------------------
// Name: fputc
//----------------------------------------------------------------------------*/
int fputc(int c, FILE *stream) {

	int r;
	__elibc_lock_stream(stream);
	r = (__elibc_fputc(c, stream, 0x02) == 0) ? c : EOF;
	__elibc_unlock_stream(stream);
	return r;
}
