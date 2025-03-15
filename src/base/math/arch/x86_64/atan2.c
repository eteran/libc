
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Computes the arc tangent of y / x using the signs of arguments to determine the correct quadrant.
 *
 * @param y the numerator
 * @param x the denominator
 * @return the principal value of the arc tangent
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
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
 * @brief Computes the arc tangent of y / x using the signs of arguments to determine the correct quadrant.
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
