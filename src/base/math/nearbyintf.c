
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Round the floating point argument x to an integer value in floating point format,
 * using the current rounding mode.
 *
 * @param x the floating point value to round
 * @return the rounded value
 */
float nearbyintf(float x) {
	return __builtin_nearbyintf(x);
}

#endif
