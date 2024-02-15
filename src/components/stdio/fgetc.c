
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fgetc
//----------------------------------------------------------------------------*/
int __elibc_fgetc(FILE *stream) {

	assert(stream);
	assert(_FDATA(stream)->orientation_set == 0 || _FDATA(stream)->orientation_wide == 0);

	_FDATA(stream)->orientation_set  = 1;
	_FDATA(stream)->orientation_wide = _ELIBC_FILE_NARROW;

	/* if this stream doesn't have a buffer, then create one */
	if (!_FDATA(stream)->buffer_start) {
		_ELIBC_ALLOCATE_FILE_BUFFER(stream);
	}

	if (_FDATA(stream)->buf_mode == _IONBF) {
		char ch;
		const ssize_t n = __elibc_sys_read(_ELIBC_FILENO(stream), &ch, sizeof(ch));

		switch (n) {
		case -1:
			_FDATA(stream)->err = 1;
			return EOF;
		case 0:
			_FDATA(stream)->eof          = 1;
			_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_start;
			_FDATA(stream)->buffer_last  = _FDATA(stream)->buffer_start;
			return EOF;
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
				return EOF;
			case 0:
				_FDATA(stream)->eof          = 1;
				_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_start;
				_FDATA(stream)->buffer_last  = _FDATA(stream)->buffer_start;
				return EOF;
			}

			_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_start;
			_FDATA(stream)->buffer_last  = _FDATA(stream)->buffer_start + n;
		}

		return *_FDATA(stream)->buffer_first++;
	}
}

/*------------------------------------------------------------------------------
// Name: fgetc
//----------------------------------------------------------------------------*/
int fgetc(FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_fgetc(stream), &r);
	return r;
}
