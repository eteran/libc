
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: __elibc_clearerr
//----------------------------------------------------------------------------*/
void __elibc_clearerr(FILE *stream) {
	assert(stream);
	_FDATA(stream)->eof = 0;
	_FDATA(stream)->err = 0;
}

/*------------------------------------------------------------------------------
// Name: clearerr
//----------------------------------------------------------------------------*/
void clearerr(FILE *stream) {
	__elibc_lock_stream(stream);
	__elibc_clearerr(stream);
	__elibc_unlock_stream(stream);
}
