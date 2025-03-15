
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Round a floating point number to the nearest integer, rounding halfway cases away from zero
 *
 * @param x the floating point number to round
 * @return the rounded floating point number
 */
long int lroundl(long double x) {
	return __builtin_lroundl(x);
}

#endif
