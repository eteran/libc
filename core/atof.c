
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: atof
//----------------------------------------------------------------------------*/
double atof(const char *nptr) {
	assert(nptr);
	return strtod(nptr, 0);
}
