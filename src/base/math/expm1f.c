
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the value of e raised to the power of a floating point number minus 1
 *
 * @param x the floating point number to compute the value of e raised to the power of minus 1
 * @return the value of e raised to the power of the floating point number minus 1
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static float __elibc_expm1f(float x) {
	return expf(x) - 1;
}

/**
 * @brief Compute the value of e raised to the power of a floating point number minus 1
 *
 * @param x the floating point number to compute the value of e raised to the power of minus 1
 * @return the value of e raised to the power of the floating point number minus 1
 */
float expm1f(float x) {
	return __elibc_expm1f(x);
}

#endif
