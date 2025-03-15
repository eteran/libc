
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the hyperbolic cosine of a floating point number
 *
 * @param x the floating point number to compute the hyperbolic cosine of
 * @return the hyperbolic cosine of the floating point number
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_cosh(double x) {
	return (exp(x) + exp(-x)) / 2;
}

/**
 * @brief Compute the hyperbolic cosine of a floating point number
 *
 * @param x the floating point number to compute the hyperbolic cosine of
 * @return the hyperbolic cosine of the floating point number
 */
double cosh(double x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 0.0 || x == -0.0) {
		return 1;
	}

	if (isinf(x)) {
		return copysign(x, 1);
	}
#endif

	return __elibc_cosh(x);
}

#endif
