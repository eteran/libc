
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name:strtof(const char *nptr, char **endptr)
//----------------------------------------------------------------------------*/
float strtof(const char *__ELIBC_RESTRICT nptr, char **__ELIBC_RESTRICT endptr) {
	assert(nptr);
	return (float)strtod(nptr, endptr);
}
