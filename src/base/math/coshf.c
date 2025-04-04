
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
_ALWAYS_INLINE _INLINE static float __elibc_coshf(float x) {
	return (expf(x) + expf(-x)) / 2;
}

/**
 * @brief Compute the hyperbolic cosine of a floating point number
 *
 * @param x the floating point number to compute the hyperbolic cosine of
 * @return the hyperbolic cosine of the floating point number
 */
float coshf(float x) {
#if !defined(__FAST_MATH__)
	if (isnan(x)) {
		return x;
	}

	if (x == 0.0 || x == -0.0) {
		return 1;
	}

	if (isinf(x)) {
		return copysignf(x, 1);
	}
#endif

	return __elibc_coshf(x);
}

#endif
