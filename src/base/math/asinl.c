
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the arc sine of a floating point number
 *
 * @param x the floating point number to compute the arc sine of
 * @return the arc sine of the floating point number
 */
long double asinl(long double x) {
	return __builtin_asinl(x);
}

#endif
