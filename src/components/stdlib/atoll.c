
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: atoll
//----------------------------------------------------------------------------*/
long long atoll(const char *nptr) {
	assert(nptr);
	return strtoll(nptr, 0, 10);
}
