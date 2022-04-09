
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: __elibc_rewind
//----------------------------------------------------------------------------*/
static void __elibc_rewind(FILE *stream) {
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
