
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the gamma function of a floating point number
 *
 * @param x the floating point number to compute the gamma function of
 * @return the gamma function of the floating point number
 */
double tgamma(double x) {
	return __builtin_tgamma(x);
}

#endif
