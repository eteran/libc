
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the fused multiply-add of three floating point numbers
 *
 * @param x the first floating point number
 * @param y the second floating point number
 * @param z the third floating point number
 * @return x * y + z
 */
static float __elibc_fmaf(float x, float y, float z) {
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
float fmaf(float x, float y, float z) {
	return __elibc_fmaf(x, y, z);
}

#endif
