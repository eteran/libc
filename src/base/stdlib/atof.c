
#define _ELIBC_SOURCE
#include <stdlib.h>

#ifdef _HAS_FPU

/**
 * @brief Convert a string to a double
 *
 * @param nptr a pointer to the string to convert
 * @return the converted double
 */
double atof(const char *nptr) {
	_LIBC_PRECOND(nptr);
	return strtod(nptr, 0);
}

#endif
