
#define _ELIBC_SOURCE
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

	if (c == EOF) {
		return EOF;
	}

	*--_FDATA(stream)->buffer_first = (char)c;
	return c;
}

/*------------------------------------------------------------------------------
// Name: ungetc
//----------------------------------------------------------------------------*/
int ungetc(int c, FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_ungetc(c, stream));
	return r;
}
