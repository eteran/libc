
#define _ELIBC_SOURCE
#include <errno.h>
#include <fenv.h>
#include <math.h>

#ifdef __SSE_MATH__
#include <immintrin.h>
#endif

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
#ifdef __SSE2_MATH__
	__m128d xmm0 = _mm_set_sd(x);
	__m128d xmm1;
	__asm__ __volatile__("sqrtsd %1, %0"
						 : "=x"(xmm1)
						 : "x"(xmm0));
	return _mm_cvtsd_f64(xmm1);
#else
	double value;
	__asm__ __volatile__("fsqrt"
						 : "=t"(value)
						 : "0"(x));
	return value;
#endif
}

/**
 * @brief Compute the square root of a floating point number
 *
 * @param x the floating point number to compute the square root of
 * @return the square root of the floating point number
 */
double
sqrt(double x) {
#if !defined(__FAST_MATH__)
	/* NOTE(eteran): the following are true because of IEEE float behavior anyway, no need to check explicitly
	 * If x is a NaN, a NaN is returned.
	 * If x is positive infinity, positive infinity is returned.
	 * If x is +0 (-0), +0 (-0) is returned. */

	/* If x is less than -0, a domain error occurs, and a NaN is returned. */
	if (x < -0.0) {
		errno = EDOM;
		feraiseexcept(FE_INVALID);
		return NAN;
	}
#endif

	return __elibc_sqrt(x);
}

#endif
