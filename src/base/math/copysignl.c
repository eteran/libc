
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Copy the sign of a floating point number
 *
 * @param x the floating point number to copy the sign of
 * @param y the floating point number to copy the sign from
 * @return the floating point number with the sign of y
 */
long double copysignl(long double x, long double y) {
	return __builtin_copysignl(x, y);
}

#endif
