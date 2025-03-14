
#define _ELIBC_SOURCE
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

/**
 * @brief Compute the absolute value of an integer
 *
 * @param j the integer to compute the absolute value of
 * @return long int the absolute value of the integer
 */
long int labs(long int j) {
	assert(j != LONG_MIN);
	return (j >= 0) ? j : -j;
}
