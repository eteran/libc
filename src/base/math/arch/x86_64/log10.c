
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the base 10 logarithm of a floating point number
 *
 * @param x the floating point number to compute the base 10 logarithm of
 * @return the base 10 logarithm of the floating point number
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_log10(double x) {
	double value;
	__asm__ __volatile__("fldlg2; fxch; fyl2x"
						 : "=t"(value)
						 : "0"(x)
						 : "st(1)");
	return value;
}

/**
 * @brief Compute the base-10 logarithm of a floating point number
 *
 * @param x the floating point number to compute the base-10 logarithm of
 * @return the base-10 logarithm of the floating point number
 */
double log10(double x) {
	return __elibc_log10(x);
}

#endif
