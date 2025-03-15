
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the absolute value of a floating point number
 *
 * @param x the floating point number to compute the absolute value of
 * @return the absolute value of the floating point number
 */
static float __elibc_fabsf(float x) {
	return x > 0 ? x : -x;
}

/**
 * @brief Compute the absolute value of a floating point number
 *
 * @param x the floating point number to compute the absolute value of
 * @return the absolute value of the floating point number
 */
float fabsf(float x) {
	return __elibc_fabsf(x);
}

#endif
