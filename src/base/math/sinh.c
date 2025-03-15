
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the hyperbolic sine of a floating point number
 *
 * @param x the floating point number to compute the hyperbolic sine of
 * @return the hyperbolic sine of the floating point number
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_sinh(double x) {
	return (exp(x) - exp(-x)) / 2;
}

/**
 * @brief Compute the hyperbolic sine of a floating point number
 *
 * @param x the floating point number to compute the hyperbolic sine of
 * @return the hyperbolic sine of the floating point number
 */
double sinh(double x) {

#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 0.0 || x == -0.0) {
		return x;
	}

	if (isinf(x)) {
		return x;
	}
#endif

	return __elibc_sinh(x);
}

#endif
