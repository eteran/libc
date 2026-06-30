
#define _ELIBC_SOURCE
#include <stdlib.h>

/**
 * @brief Convert a string to an integer
 *
 * @param nptr a pointer to the string to convert
 * @return the converted integer
 */
int atoi(const char *nptr) {
	_LIBC_PRECOND(nptr);
	return (int)strtol(nptr, 0, 10);
}
