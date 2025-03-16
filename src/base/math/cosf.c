
#define _ELIBC_SOURCE
#include <errno.h>
#include <fenv.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the cosine of a floating point number
 *
 * @param x the floating point number to compute the cosine of
 * @return the cosine of the floating point number
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static float __elibc_cosf(float x) {
	return sinf(x + (M_PIf / 2.0F));
}

/**
 * @brief Compute the cosine of a floating point number
 *
 * @param x the floating point number to compute the cosine of
 * @return the cosine of the floating point number
 */
float cosf(float x) {

#if !defined(__FAST_MATH__)
	if (isnan(x)) {
		return x;
	}

	if (isinf(x)) {
		errno = EDOM;
		feraiseexcept(FE_INVALID);
		return NAN;
	}
#endif

	return __elibc_cosf(x);
}

#endif
