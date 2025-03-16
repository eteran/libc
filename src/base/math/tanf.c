
#define _ELIBC_SOURCE
#include <errno.h>
#include <fenv.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the tangent of a floating point number
 *
 * @param x the floating point number to compute the tangent of
 * @return the tangent of the floating point number
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static float __elibc_tanf(float x) {

	/* TODO(eteran): account for possible overflow */
	const float cos_val = cosf(x);
	if (cos_val != 0.0) {
		return sinf(x) / cos_val;
	} else {
		errno = EDOM;
		return 0.0F;
	}
}

/**
 * @brief Compute the tangent of a floating point number
 *
 * @param x the floating point number to compute the tangent of
 * @return the tangent of the floating point number
 */
float tanf(float x) {
#if !defined(__FAST_MATH__)
	if (isnan(x)) {
		errno = EDOM;
		return x;
	}

	if (isinf(x)) {
		errno = EDOM;
		feraiseexcept(FE_INVALID);
		return NAN;
	}
#endif

	return __elibc_tanf(x);
}

#endif
