
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Raise a floating point number to the power of another
 *
 * @param x the base
 * @param y the exponent
 * @return the value of x raised to the power of y
 */
long double powl(long double x, long double y) {
	return __builtin_powl(x, y);
}

#endif
