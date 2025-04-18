
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Rounds the floating point argument x to an integer value,
 * using the current rounding mode.
 *
 * @param x the floating point value to round
 * @return the rounded value
 */
long int lrint(double x) {
	return __builtin_lrint(x);
}

#endif
