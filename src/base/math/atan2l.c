
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the principal value of the arc tangent of y/x, using the signs of the two arguments
 * to determine the quadrant of the result
 *
 * @param y the numerator
 * @param x the denominator
 * @return the principal value of the arc tangent
 */
long double atan2l(long double x, long double y) {
	return __builtin_atan2l(x, y);
}

#endif
