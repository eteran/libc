
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: __elibc_ferror
//----------------------------------------------------------------------------*/
static int __elibc_ferror(FILE *stream) {
	assert(stream);
	return _FDATA(stream)->err != 0;
}

/*------------------------------------------------------------------------------
// Name: ferror
//----------------------------------------------------------------------------*/
int ferror(FILE *stream) {
	int r;
	__elibc_lock_stream(stream);
	r = __elibc_ferror(stream);
	__elibc_unlock_stream(stream);
	return r;
}
