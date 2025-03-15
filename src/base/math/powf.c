
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Raise a floating point number to the power of another
 *
 * @param x the base
 * @param y the exponent
 * @return the value of x raised to the power of y
 */
float powf(float x, float y) {
	return __builtin_powf(x, y);
}

#endif
