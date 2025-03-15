
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Round a floating point number to the nearest integer, using the current rounding direction
 *
 * @param x the floating point number to round
 * @return the rounded floating point number
 */
long int lrintl(long double x) {
	return __builtin_lrintl(x);
}

#endif
