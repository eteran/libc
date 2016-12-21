
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <assert.h>

#if !defined(__x86_64__) || defined(__SSE__)
/*------------------------------------------------------------------------------
// Name:strtof(const char *nptr, char **endptr)
//----------------------------------------------------------------------------*/
float strtof(const char *__ELIBC_RESTRICT nptr, char **__ELIBC_RESTRICT endptr) {
	assert(nptr);
	return (float)strtod(nptr, endptr);
}
#endif
