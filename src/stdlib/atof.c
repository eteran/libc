
#define __ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: atof
//----------------------------------------------------------------------------*/
double atof(const char *nptr) {
	assert(nptr);
	return strtod(nptr, 0);
}

#endif
