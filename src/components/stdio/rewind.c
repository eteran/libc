
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: __elibc_rewind
//----------------------------------------------------------------------------*/
static int __elibc_rewind(FILE *stream) {
	assert(stream);
	__elibc_fseek(stream, 0L, SEEK_SET);
	__elibc_clearerr(stream);
	return 0;
}

/*------------------------------------------------------------------------------
// Name: rewind
//----------------------------------------------------------------------------*/
void rewind(FILE *stream) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_rewind(stream), &r);
	(void)r;
}
