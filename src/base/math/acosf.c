
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Computes the arc cosine of a floating point number.
 *
 * @param x The value for which to compute the arc cosine.
 * @return The arc cosine of the input value.
 * @note This function uses the inverse sine function to compute the arc cosine.
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static float __elibc_acosf(float x) {
	return (M_PIf / 2.0f) - asinf(x);
}

/**
 * @brief Computes the arc cosine of a floating point number.
 *
 * @param x The value for which to compute the arc cosine.
 * @return The arc cosine of the input value.
 */
float acosf(float x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 1.0f) {
		return 0.0f;
	}

	if (isinf(x)) {
		errno = EDOM;
		return NAN;
	}

	if (x < -1 || x > 1) {
		errno = EDOM;
		return NAN;
	}
#endif

	return __elibc_acosf(x);
}

#endif
