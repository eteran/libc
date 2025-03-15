
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the arc tangent of a floating point number
 *
 * @param x the floating point number to compute the arc tangent of
 * @return the arc tangent of the floating point number
 */
long double atanl(long double x) {
	return __builtin_atanl(x);
}

#endif
