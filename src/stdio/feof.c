
#define __ELIBC_SOURCE
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
	__elibc_lock_stream(stream);
	r = __elibc_feof(stream);
	__elibc_unlock_stream(stream);
	return r;
}
