
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the natural logarithm of the gamma function
 *
 * @param x the floating point number to compute the natural logarithm of the gamma function of
 * @return the natural logarithm of the gamma function of the floating point number
 */
double lgamma(double x) {
	return __builtin_lgamma(x);
}

#endif
