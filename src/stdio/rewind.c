
#define __ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: __elibc_rewind
//----------------------------------------------------------------------------*/
void __elibc_rewind(FILE *stream) {
	assert(stream);
	__elibc_fseek(stream, 0L, SEEK_SET);
	__elibc_clearerr(stream);
}

/*------------------------------------------------------------------------------
// Name: rewind
//----------------------------------------------------------------------------*/
void rewind(FILE *stream) {
	__elibc_lock_stream(stream);
	__elibc_rewind(stream);
	__elibc_unlock_stream(stream);
}
