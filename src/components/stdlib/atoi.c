
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: atoi
//----------------------------------------------------------------------------*/
int atoi(const char *nptr) {
	assert(nptr);
	return (int)strtol(nptr, 0, 10);
}
