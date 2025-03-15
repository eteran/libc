
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Computes the arc tangent of y / x using the signs of arguments to determine the correct quadrant.
 *
 * @param y the numerator
 * @param x the denominator
 * @return the principal value of the arc tangent
 */
float atan2f(float x, float y) {
	return __builtin_atan2f(x, y);
}

#endif
