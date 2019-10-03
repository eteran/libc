
#define __ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: atol
//----------------------------------------------------------------------------*/
long atol(const char *nptr) {
	assert(nptr);
	return strtol(nptr, 0, 10);
}
