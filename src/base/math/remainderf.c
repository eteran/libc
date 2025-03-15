
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the remainder of the division of two floating point numbers
 *
 * @param x the dividend
 * @param y the divisor
 * @return The remainder division of x by y.
 */
float remainderf(float x, float y) {
	return __builtin_remainderf(x, y);
}

#endif
