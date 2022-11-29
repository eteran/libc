
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: __elibc_ungetc
//----------------------------------------------------------------------------*/
static int __elibc_ungetc(int c, FILE *stream) {

	assert(stream);
	assert(_FDATA(stream)->orientation != _ELIBC_FILE_ORIENTATION_WIDE);

	_FDATA(stream)->orientation = _ELIBC_FILE_ORIENTATION_NARROW;

	if (_FDATA(stream)->buffer_first == _FDATA(stream)->buffer_start) {
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
