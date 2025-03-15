
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the arc tangent of a floating point number
 *
 * @param x the floating point number to compute the arc tangent of
 * @return the arc tangent of the floating point
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_atan(double x) {
	double value;
	__asm__ __volatile__("fld1; fpatan"
						 : "=t"(value)
						 : "0"(x)
						 : "st(1)");
	return value;
}

/**
 * @brief Compute the arc tangent of a floating point number
 *
 * @param x the floating point number to compute the arc tangent of
 * @return the arc tangent of the floating point
 */
double atan(double x) {
	return __elibc_atan(x);
}

#endif
