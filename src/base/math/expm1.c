
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the value of e raised to the power of a floating point number minus 1
 *
 * @param x the floating point number to compute the value of e raised to the power of minus 1
 * @return the value of e raised to the power of the floating point number minus 1
 */
_ALWAYS_INLINE _INLINE static double __elibc_expm1(double x) {
	return exp(x) - 1;
}

/**
 * @brief Compute the value of e raised to the power of a floating point number minus 1
 *
 * @param x the floating point number to compute the value of e raised to the power of minus 1
 * @return the value of e raised to the power of the floating point number minus 1
 */
double expm1(double x) {
	return __elibc_expm1(x);
}

#endif
