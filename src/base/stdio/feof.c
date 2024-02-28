
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: __elibc_feof
//----------------------------------------------------------------------------*/
static int __elibc_feof(FILE *stream) {
	assert(stream);
	return _FDATA(stream)->eof != 0;
}

/*------------------------------------------------------------------------------
// Name: feof
//----------------------------------------------------------------------------*/
int feof(FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_feof(stream), &r);
	return r;
}
