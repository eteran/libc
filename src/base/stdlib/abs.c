
#define _ELIBC_SOURCE
#include <limits.h>
#include <stdlib.h>

/**
 * @brief Compute the absolute value of an integer
 *
 * @param j the integer to compute the absolute value of
 * @return the absolute value of the integer
 */
int abs(int j) {
	_LIBC_PRECOND(j != INT_MIN);
	return (j >= 0) ? j : -j;
}
