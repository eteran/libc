
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Computes the nearest integer value to x, rounding halfway cases away from zero,
 * regardless of the current rounding mode.
 *
 * @param x the floating point number to round
 * @return the rounded floating point number
 */
long long int llround(double x) {
	return __builtin_llround(x);
}

#endif
