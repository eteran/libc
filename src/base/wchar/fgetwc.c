
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

/**
 * @brief Determine the expected length of a UTF-8 character
 *
 * @param ch the character to determine the length of
 * @return the expected length of the UTF-8 character, or -1 if the character is invalid
 */
static int __elibc_expected_length(wint_t ch) {
	if ((ch & 0x80) == 0) {
		return 1;
	} else if ((ch & 0xe0) == 0xc0) {
		return 2;
	} else if ((ch & 0xf0) == 0xe0) {
		return 3;
	} else if ((ch & 0xf8) == 0xf0) {
		return 4;
	} else if ((ch & 0xfc) == 0xf8) {
		return -1; /* Restricted by RFC 3629 */
#if 0
		return 5;
#endif
	} else if ((ch & 0xfe) == 0xfc) {
		return -1; /* Restricted by RFC 3629 */
#if 0
		return 6;
#endif
	} else {
		return -1;
	}
}

/**
 * @brief Read a wide character from a stream
 *
 * @param stream the input stream to read from
 * @return the byte of the next wide character read, or WEOF if an error occurred or the end of the stream was reached
 */
static wint_t __elibc_fgetwc(FILE *stream) {

	assert(stream);
	assert(_FDATA(stream)->orientation_set == 0 || _FDATA(stream)->orientation_wide == 1);

	_FDATA(stream)->orientation_set  = 1;
	_FDATA(stream)->orientation_wide = _ELIBC_FILE_WIDE;

	/* if this stream doesn't have a buffer, then create one */
	if (!_FDATA(stream)->buffer_start) {
		_ELIBC_ALLOCATE_FILE_BUFFER(stream);
	}

	if (_FDATA(stream)->buf_mode == _IONBF) {
		unsigned char ch;
		const ssize_t n = __elibc_sys_read(_ELIBC_FILENO(stream), &ch, sizeof(ch));

		switch (n) {
		case -1:
			_FDATA(stream)->err = 1;
			return WEOF;
		case 0:
			_FDATA(stream)->eof          = 1;
			_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_start;
			_FDATA(stream)->buffer_last  = _FDATA(stream)->buffer_start;
			return WEOF;
		default:
			return ch;
		}
	} else {
		/* the input buffer is empty, fill it up */
		if (_FDATA(stream)->buffer_first == _FDATA(stream)->buffer_last) {
			const ssize_t n = __elibc_sys_read(_ELIBC_FILENO(stream),
											   _FDATA(stream)->buffer_start,
											   _ELIBC_STREAM_BUFFER_SIZE(stream));

			switch (n) {
			case -1:
				_FDATA(stream)->err = 1;
				return WEOF;
			case 0:
				_FDATA(stream)->eof          = 1;
				_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_start;
				_FDATA(stream)->buffer_last  = _FDATA(stream)->buffer_start;
				return WEOF;
			}

			_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_start;
			_FDATA(stream)->buffer_last  = _FDATA(stream)->buffer_start + n;
		}

		return (unsigned char)*_FDATA(stream)->buffer_first++;
	}
}

/**
 * @brief Read a multibyte character from a stream (thread-unsafe)
 *
 * @param stream the input stream to read from
 * @param buf the buffer to store the read character
 * @return the number of bytes read, or -1	 if an error occurred or the end of the stream was reached
 */
static int __elibc_fgetwc_unlocked(FILE *stream, char *buf) {
	wint_t r;
	int i;
	int n = 0;

	/* read a character */
	r = __elibc_fgetwc(stream);
	if (r == WEOF) {
		return WEOF;
	}

	/* ok so the first one was read ok. given our locale,
	 * how many bytes do we expect to come?
	 */

	/* NOTE(eteran): we assume UTF-8 for now */
	n = __elibc_expected_length(r);
	if (n < 1) {
		return WEOF;
	}

	/* put the first one in the buffer */
	buf[0] = (char)r;

	/* read the next N characters */
	for (i = 1; i < n; ++i) {
		r = __elibc_fgetwc(stream);
		if (r == WEOF) {
			return WEOF;
		}

		buf[i] = (char)r;
	}

	return n;
}

/**
 * @brief Read a wide character from a stream
 *
 * @param stream the input stream to read from
 * @return the wide character read, or WEOF if an error occurred or the end of the stream was reached
 */
wint_t fgetwc(FILE *stream) {

	int r;
	char buf[MB_LEN_MAX];
	wchar_t wc;

	__ELIBC_WITH_LOCK(__elibc_fgetwc_unlocked(stream, buf), &r);

	if (r > 0) {
		if (mbtowc(&wc, buf, (size_t)r) == r) {
			return (wint_t)wc;
		}
	}
	return WEOF;
}
