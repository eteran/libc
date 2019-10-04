
#define __ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: __elibc_ungetc
//----------------------------------------------------------------------------*/
static int __elibc_ungetc(int c, FILE *stream) {

	assert(stream);
	assert(_FDATA(stream)->orientation != 0x03);

	_FDATA(stream)->orientation = 0x02;

	if (_FDATA(stream)->buffer_first == _FDATA(stream)->buffer_ptr) {
		return EOF;
	}

	return *--_FDATA(stream)->buffer_first = (unsigned char)c;
}

/*------------------------------------------------------------------------------
// Name: ungetc
//----------------------------------------------------------------------------*/
int ungetc(int c, FILE *stream) {
	int r;
	__elibc_lock_stream(stream);
	r = __elibc_ungetc(c, stream);
	__elibc_unlock_stream(stream);
	return r;
}
