
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the cube root of a floating point number
 *
 * @param x the floating point number to compute the cube root of
 * @return the cube root of the floating point number
 */
long double cbrtl(long double x) {
	return __builtin_cbrtl(x);
}

#endif
