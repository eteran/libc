
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: ftell
//----------------------------------------------------------------------------*/
long ftell(FILE *stream) {

	assert(stream);
	return (long)__elibc_sys_lseek(_ELIBC_FILENO(stream), 0, SEEK_CUR);
}
