
#define _ELIBC_SOURCE
#include <stdlib.h>

/**
 * @brief Convert a string to a long long integer
 *
 * @param nptr a pointer to the string to convert
 * @return the converted long long integer
 */
long long atoll(const char *nptr) {
	_LIBC_PRECOND(nptr);
	return strtoll(nptr, 0, 10);
}
