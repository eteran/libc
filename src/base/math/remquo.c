
#define _ELIBC_SOURCE

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
double remquo(double x, double y, int *quo) {
	return __builtin_remquo(x, y, quo);
}

#endif
