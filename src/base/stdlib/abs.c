
#define _ELIBC_SOURCE
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

/**
 * @brief Compute the absolute value of an integer
 *
 * @param j the integer to compute the absolute value of
 * @return int the absolute value of the integer
 */
int abs(int j) {
	assert(j != INT_MIN);
	return (j >= 0) ? j : -j;
}
