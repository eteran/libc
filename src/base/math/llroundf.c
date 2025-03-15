
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
long long int llroundf(float x) {
	return __builtin_llroundf(x);
}

#endif
