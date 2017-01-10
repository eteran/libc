
#define __ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>
#include "c/_support.h"

/*------------------------------------------------------------------------------
// Name: ftell
//----------------------------------------------------------------------------*/
long ftell(FILE *stream) {

	assert(stream);
	return (long)__elibc_sys_lseek(__ELIBC_FILENO(stream), 0, SEEK_CUR);
}
