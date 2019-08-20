
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: atoll
//----------------------------------------------------------------------------*/
long long atoll(const char *nptr) {
	assert(nptr);
	return strtoll(nptr, 0, 10);
}
