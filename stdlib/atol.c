
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: atol
//----------------------------------------------------------------------------*/
long atol(const char *nptr) {
	assert(nptr);
	return strtol(nptr, 0, 10);
}
