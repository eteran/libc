
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

/**
 * @brief Convert a string to a long integer
 *
 * @param nptr a pointer to the string to convert
 * @return the converted long integer
 */
long atol(const char *nptr) {
	assert(nptr);
	return strtol(nptr, 0, 10);
}
