
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the arc tangent of a floating point number
 *
 * @param x the floating point number to compute the arc tangent of
 * @return the arc tangent of the floating point number
 */
long double atanhl(long double x) {
	return __builtin_atanhl(x);
}

#endif
