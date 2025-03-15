
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the remainder of the division of two floating point numbers
 *
 * @param x the dividend
 * @param y the divisor
 * @return the remainder of the division
 */
_ALWAYS_INLINE _INLINE static double __elibc_fmod(double x, double y) {
	double value;
	__asm __volatile__("1: fprem    \n"
					   "fnstsw %%ax \n"
					   "sahf        \n"
					   "jp 1b       \n"
					   : "=t"(value)
					   : "0"(x), "u"(y)
					   : "ax", "cc");
	return value;
}

/**
 * @brief Compute the remainder of the division of two floating point numbers
 *
 * @param x the dividend
 * @param y the divisor
 * @return the remainder of the division
 */
double fmod(double x, double y) {
	return __elibc_fmod(x, y);
}

#endif
