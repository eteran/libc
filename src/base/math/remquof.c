
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the remainder of the division of two floating point numbers
 *
 * @param x the dividend
 * @param y the divisor
 * @param quo pointer to an integer where a few bits of the quotient will be stored
 * @return The remainder division of x by y.
 */
float remquof(float x, float y, int *quo) {
	return __builtin_remquof(x, y, quo);
}

#endif
