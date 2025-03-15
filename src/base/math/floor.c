
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the largest integer value less than or equal to a floating point number
 *
 * @param x the floating point number to compute the largest integer value less than or equal to
 * @return the largest integer value less than or equal to the floating point number
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_floor(double x) {
	return __builtin_floor(x);
}

/**
 * @brief Compute the largest integer value less than or equal to a floating point number
 *
 * @param x the floating point number to compute the largest integer value less than or equal to
 * @return the largest integer value less than or equal to the floating point number
 */
double floor(double x) {
	return __elibc_floor(x);
}

#endif
