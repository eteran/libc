
#define _ELIBC_SOURCE
#include <errno.h>
#include <fenv.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the sine of a floating point number
 *
 * @param x the floating point number to compute the sine of
 * @return the sine of the floating point number
 * @note    The input value is in radians.
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_sin(double x) {
	double value;
	__asm__ __volatile__("fsin"
						 : "=t"(value)
						 : "0"(x));
	return value;
}

/**
 * @brief Compute the sine of a floating point number
 *
 * @param x the floating point number to compute the sine of
 * @return the sine of the floating point number
 * @note    The input value is in radians.
 */
double sin(double x) {
#ifndef __FAST_MATH__
	if (x == 0.0) {
		return x;
	}

	if (isnan(x)) {
		return x;
	}

	if (isinf(x)) {
		errno = EDOM;
		feraiseexcept(FE_INVALID);
		return NAN;
	}
#endif

	return __elibc_sin(x);
}

#endif
