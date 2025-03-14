
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Computes the arc sine of a given value using the inverse tangent function.
 *
 * @param x The value for which to compute the arc sine.
 * @return float The arc sine of the input value.
 */
_ALWAYS_INLINE static float __elibc_asinf(float x) {
	return atanf(x / sqrtf(1 - (x * x)));
}

/**
 * @brief Computes the arc sine of a given value.
 *
 * @param x The value for which to compute the arc sine.
 * @return float The arc sine of the input value.
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
