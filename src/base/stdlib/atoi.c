
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

/**
 * @brief Convert a string to an integer
 *
 * @param nptr a pointer to the string to convert
 * @return the converted integer
 */
int atoi(const char *nptr) {
	assert(nptr);
	return (int)strtol(nptr, 0, 10);
}
