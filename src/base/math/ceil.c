
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the smallest integer value not less than x
 *
 * @param x the floating point number to compute the smallest integer value not less than
 * @return the smallest integer value not less than x
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_ceil(double x) {
	return __builtin_ceil(x);
}

/**
 * @brief Compute the smallest integer value not less than x
 *
 * @param x the floating point number to compute the smallest integer value not less than
 * @return the smallest integer value not less than x
 */
double ceil(double x) {
	return __elibc_ceil(x);
}

#endif
