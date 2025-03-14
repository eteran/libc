
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the square root of a floating point number
 *
 * @param x the floating point number to compute the square root of
 * @return the square root of the floating point number
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_sqrt(double x) {
	double value;
	__asm__ __volatile__("fsqrt"
						 : "=t"(value)
						 : "0"(x));
	return value;
}

/**
 * @brief Compute the square root of a floating point number
 *
 * @param x the floating point number to compute the square root of
 * @return the square root of the floating point number
 */
double sqrt(double x) {
#ifndef __FAST_MATH__
	if (x < -0) {
		errno = EDOM;
		return NAN;
	}

	if (isnan(x)) {
		return x;
	}

	if (isinf(x)) {
		return x;
	}

	if (x == 0.0 || x == -0.0) {
		return x;
	}
#endif

	return __elibc_sqrt(x);
}

#endif
