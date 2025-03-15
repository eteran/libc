
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the error function of a floating point number
 *
 * @param x the floating point number to compute the error function of
 * @return the error function of the floating point number
 */
double erf(double x) {
	return __builtin_erf(x);
}

#endif
