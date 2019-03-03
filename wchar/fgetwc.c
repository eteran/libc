
#define __ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>
#include <assert.h>
#include <stdlib.h>
#include <wctype.h>
#include <limits.h>
#include "c/_support.h"

/*------------------------------------------------------------------------------
// Name: __elibc_fgetwc
//----------------------------------------------------------------------------*/
static int expected_length(wint_t ch) {
	if((ch & 0x80) == 0) {
		return 1;
	} else if((ch & 0xe0) == 0xc0) {
		return 2;
	} else if((ch & 0xf0) == 0xe0) {
		return 3;
	} else if((ch & 0xf8) == 0xf0) {
		return 4;
	} else if((ch & 0xfc) == 0xf8) {
		return -1; /* Restricted by RFC 3629 */
	#if 0
		return 5;
	#endif
	} else if((ch & 0xfe) == 0xfc) {
		return -1; /* Restricted by RFC 3629 */
	#if 0
		return 6;
	#endif
	} else {
		return -1;
	}
}


/*------------------------------------------------------------------------------
// Name: __elibc_fgetwc
// Desc: reads a single byte from the stream for use in a MB character
// TODO(eteran): figure out the best way to reuse the code from __elibc_fgetc here
//----------------------------------------------------------------------------*/
wint_t __elibc_fgetwc(FILE *stream) {

	assert(stream);
	assert(_FDATA(stream)->orientation != 0x02);

	_FDATA(stream)->orientation = 0x03;

	/* if this stream doesn't have a buffer, then create one */
	if(!_FDATA(stream)->buffer_ptr) {
		char * const buffer = malloc(BUFSIZ);
		_FDATA(stream)->buffer_ptr       = buffer;
		_FDATA(stream)->buffer_first     = buffer;
		_FDATA(stream)->buffer_last      = buffer;
		_FDATA(stream)->buffer_capacity  = BUFSIZ;

		/* record this so we can free it */
		_FDATA(stream)->internal_buffer_ptr = buffer;
	}

	if(_FDATA(stream)->buf_mod == _IONBF) {
		char ch;
		const ssize_t n = __elibc_sys_read(__ELIBC_FILENO(stream), &ch, sizeof(ch));

		switch(n) {
		case -1:
			_FDATA(stream)->err = 1;
			return WEOF;
		case 0:
			_FDATA(stream)->eof = 1;
			_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_ptr;
			_FDATA(stream)->buffer_last  = _FDATA(stream)->buffer_ptr;
			return WEOF;
		default:
			return ch;
		}
	} else {
		/* the input buffer is empty, fill it up */
		if(_FDATA(stream)->buffer_first == _FDATA(stream)->buffer_last) {
			const ssize_t n = __elibc_sys_read(
				__ELIBC_FILENO(stream),
				_FDATA(stream)->buffer_ptr,
				_FDATA(stream)->buffer_capacity);

			switch(n) {
			case -1:
				_FDATA(stream)->err = 1;
				return WEOF;
			case 0:
				_FDATA(stream)->eof = 1;
				_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_ptr;
				_FDATA(stream)->buffer_last  = _FDATA(stream)->buffer_ptr;
				return WEOF;
			}

			_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_ptr;
			_FDATA(stream)->buffer_last  = _FDATA(stream)->buffer_ptr + n;
		}

		return *_FDATA(stream)->buffer_first++;
	}
}

/*------------------------------------------------------------------------------
// Name: __elibc_fgetwc_unlocked
// Desc: returns WEOF or the number of bytes reads
//----------------------------------------------------------------------------*/
static wint_t __elibc_fgetwc_unlocked(FILE *stream, char *buf) {
	wint_t r;
	int    i;
	int    n = 0;

	/* read a character */
	r = __elibc_fgetwc(stream);
	if(r == WEOF) {
		return WEOF;
	}

	/* ok so the first one was read ok. given out locale,
	 * how many bytes do we expect to come?
	 */

	/* NOTE(eteran): we assume UTF-8 for now */
	n = expected_length(r);
	if(n < 1) {
		return WEOF;
	}

	/* put the first one in the buffer */
	buf[0] = (char)r;

	/* read the next N characters */
	for(i = 1; i < n; ++i) {
		r = __elibc_fgetwc(stream);
		if(r == WEOF) {
			return WEOF;
		}

		buf[i] = (char)r;
	}


	return n;
}

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
wint_t fgetwc(FILE *stream) {

	wint_t  n;
	char    buf[MB_LEN_MAX];
	wchar_t wc;

	__elibc_lock_stream(stream);
	n = __elibc_fgetwc_unlocked(stream, buf);
	__elibc_unlock_stream(stream);

	if(n > 0) {
		if((wint_t)mbtowc(&wc, buf, n) == n) {
			return (wint_t)wc;
		}
	}
	return WEOF;
}
