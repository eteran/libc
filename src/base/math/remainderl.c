
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the IEEE remainder of the floating point division operation x / y.
 *
 * @param x the dividend
 * @param y the divisor
 * @return The remainder division of x by y.
 * @note  The returned value is not guaranteed to have the same sign as x.
 */
long double remainderl(long double x, long double y) {
	return __builtin_remainderl(x, y);
}

#endif
