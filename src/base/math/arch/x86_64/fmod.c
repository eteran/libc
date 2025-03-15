
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the floating point remainder of the division operation x / y
 *
 * @param x the dividend
 * @param y the divisor
 * @return the remainder of the division
 * @note The returned value has the same sign as x and is less than y in magnitude.
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
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
 * @brief Compute the floating point remainder of the division operation x / y
 *
 * @param x the dividend
 * @param y the divisor
 * @return the remainder of the division
 * @note The returned value has the same sign as x and is less than y in magnitude.
 */
double fmod(double x, double y) {
	return __elibc_fmod(x, y);
}

#endif
