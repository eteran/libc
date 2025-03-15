
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Round a floating point number to the nearest integer, but round halfway cases away from zero
 * (regardless of the current rounding direction
 *
 * @param x the floating point number to round
 * @return the rounded floating point number
 */
float roundf(float x) {
	return __builtin_roundf(x);
}

#endif
