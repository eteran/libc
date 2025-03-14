
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

/**
 * @brief Convert a string to a long long integer
 *
 * @param nptr a pointer to the string to convert
 * @return long long int the converted long long integer
 */
long long atoll(const char *nptr) {
	assert(nptr);
	return strtoll(nptr, 0, 10);
}
