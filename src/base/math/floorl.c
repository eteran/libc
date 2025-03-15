
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the largest integer value less than or equal to a floating point number
 *
 * @param x the floating point number to compute the largest integer value less than or equal to
 * @return the largest integer value less than or equal to the floating point number
 */
long double floorl(long double x) {
	return __builtin_floorl(x);
}

#endif
