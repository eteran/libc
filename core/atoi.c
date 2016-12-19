
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: atoi
//----------------------------------------------------------------------------*/
int atoi(const char *nptr) {
	assert(nptr);
	return (int)strtol(nptr, 0, 10);
}
