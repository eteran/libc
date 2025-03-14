
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

#ifdef _HAS_FPU

/**
 * @brief Convert a string to a double
 *
 * @param nptr a pointer to the string to convert
 * @return double the converted double
 */
double atof(const char *nptr) {
	assert(nptr);
	return strtod(nptr, 0);
}

#endif
