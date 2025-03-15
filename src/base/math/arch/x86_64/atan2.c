
#define _ELIBC_SOURCE
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
_ALWAYS_INLINE _INLINE static double __elibc_atan2(double y, double x) {
	double value;
	__asm__ __volatile__("fpatan"
						 : "=t"(value)
						 : "0"(x), "u"(y)
						 : "st(1)");
	return value;
}

/**
 * @brief Compute the principal value of the arc tangent of y/x, using the signs of the two arguments
 * to determine the quadrant of the result
 *
 * @param y the numerator
 * @param x the denominator
 * @return the principal value of the arc tangent
 */
double atan2(double y, double x) {

#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (isnan(y)) {
		return y;
	}
#endif

	return __elibc_atan2(y, x);
}

#endif
