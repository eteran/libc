
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <assert.h>

#if !defined(__x86_64__) || defined(__SSE__)
/*------------------------------------------------------------------------------
// Name: atof
//----------------------------------------------------------------------------*/
double atof(const char *nptr) {
	assert(nptr);
	return strtod(nptr, 0);
}
#endif
