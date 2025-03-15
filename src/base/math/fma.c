
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the fused multiply-add of three floating point numbers
 *
 * @param x the first floating point number
 * @param y the second floating point number
 * @param z the third floating point number
 * @return x * y + z
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_fma(double x, double y, double z) {
	/* TODO(eteran): account for errors, and rounding mode */
	return x * y + z;
}

/**
 * @brief Compute the fused multiply-add of three floating point numbers
 *
 * @param x the first floating point number
 * @param y the second floating point number
 * @param z the third floating point number
 * @return x * y + z
 */
double fma(double x, double y, double z) {
	return __elibc_fma(x, y, z);
}

#endif
