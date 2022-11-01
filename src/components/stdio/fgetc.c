
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
	assert(_FDATA(stream)->orientation != 0x03);

	_FDATA(stream)->orientation = 0x02;

	/* if this stream doesn't have a buffer, then create one */
	if (!_FDATA(stream)->buffer_ptr) {
		char *const buffer = malloc(BUFSIZ);
		_FDATA(stream)->buffer_ptr = buffer;
		_FDATA(stream)->buffer_first = buffer;
		_FDATA(stream)->buffer_last = buffer;
		_FDATA(stream)->buffer_capacity = BUFSIZ;

		/* record this so we can free it */
		_FDATA(stream)->internal_buffer_ptr = buffer;
	}

	if (_FDATA(stream)->buf_mod == _IONBF) {
		char ch;
		const ssize_t n = __elibc_sys_read(_ELIBC_FILENO(stream), &ch, sizeof(ch));

		switch (n) {
		case -1:
			_FDATA(stream)->err = 1;
			return EOF;
		case 0:
			_FDATA(stream)->eof = 1;
			_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_ptr;
			_FDATA(stream)->buffer_last = _FDATA(stream)->buffer_ptr;
			return EOF;
		default:
			return ch;
		}
	} else {
		/* the input buffer is empty, fill it up */
		if (_FDATA(stream)->buffer_first == _FDATA(stream)->buffer_last) {
			const ssize_t n = __elibc_sys_read(_ELIBC_FILENO(stream), _FDATA(stream)->buffer_ptr,
			                                   _FDATA(stream)->buffer_capacity);

			switch (n) {
			case -1:
				_FDATA(stream)->err = 1;
				return EOF;
			case 0:
				_FDATA(stream)->eof = 1;
				_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_ptr;
				_FDATA(stream)->buffer_last = _FDATA(stream)->buffer_ptr;
				return EOF;
			}

			_FDATA(stream)->buffer_first = _FDATA(stream)->buffer_ptr;
			_FDATA(stream)->buffer_last = _FDATA(stream)->buffer_ptr + n;
		}

		return *_FDATA(stream)->buffer_first++;
	}
}

/*------------------------------------------------------------------------------
// Name: fgetc
//----------------------------------------------------------------------------*/
int fgetc(FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_fgetc(stream));
	return r;
}
