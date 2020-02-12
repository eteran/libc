
#define __ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name:strtof(const char *nptr, char **endptr)
//----------------------------------------------------------------------------*/
float strtof(const char *_RESTRICT nptr, char **_RESTRICT endptr) {
	assert(nptr);
	return (float)strtod(nptr, endptr);
}

#endif
