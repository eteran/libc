
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the absolute value of a floating point number
 *
 * @param x the floating point number to compute the absolute value of
 * @return the absolute value of the floating point number
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static long double __elibc_fabsl(long double x) {
	return x > 0 ? x : -x;
}

/**
 * @brief Compute the absolute value of a floating point number
 *
 * @param x the floating point number to compute the absolute value of
 * @return the absolute value of the floating point number
 */
long double fabsl(long double x) {
	return __elibc_fabsl(x);
}

#endif
