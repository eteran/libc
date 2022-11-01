
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: __elibc_clearerr
//----------------------------------------------------------------------------*/
int __elibc_clearerr(FILE *stream) {
	assert(stream);
	_FDATA(stream)->eof = 0;
	_FDATA(stream)->err = 0;
	return 0;
}

/*------------------------------------------------------------------------------
// Name: clearerr
//----------------------------------------------------------------------------*/
void clearerr(FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_clearerr(stream));
	(void)r;
}
