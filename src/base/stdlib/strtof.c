
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

#ifdef _HAS_FPU

/**
 * @brief Convert a string to a float
 *
 * @param nptr the string to be converted
 * @param endptr a pointer to a pointer to the first invalid character in the string
 * @return float the converted value
 */
float strtof(const char *_RESTRICT nptr, char **_RESTRICT endptr) {
	assert(nptr);
	return (float)strtod(nptr, endptr);
}

#endif
