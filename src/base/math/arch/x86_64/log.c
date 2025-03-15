
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the natural logarithm of a floating point number
 *
 * @param x the floating point number to compute the natural logarithm of
 * @return the natural logarithm of the floating point number
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
double __elibc_log(double x) {
	double value;
	__asm__ __volatile__("fldln2; fxch; fyl2x"
						 : "=t"(value)
						 : "0"(x)
						 : "st(1)");
	return value;
}

/**
 * @brief Compute the natural logarithm of a floating point number
 *
 * @param x the floating point number to compute the natural logarithm of
 * @return the natural logarithm of the floating point number
 */
double log(double x) {
	return __elibc_log(x);
}

#endif
