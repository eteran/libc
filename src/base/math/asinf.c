
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Computes the arc sine of a floating point number using the inverse tangent function.
 *
 * @param x The value for which to compute the arc sine.
 * @return The arc sine of the input value.
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static float __elibc_asinf(float x) {
	return atanf(x / sqrtf(1 - (x * x)));
}

/**
 * @brief Computes the arc sine of a floating point number.
 *
 * @param x The value for which to compute the arc sine.
 * @return The arc sine of the input value.
 */
float asinf(float x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 0.0) {
		return x;
	}

	if (x < -1 || x > 1) {
		errno = EDOM;
		return NAN;
	}
#endif

	return __elibc_asinf(x);
}

#endif
