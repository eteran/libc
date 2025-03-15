
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the largest integer value less than or equal to a floating point number
 *
 * @param x the floating point number to compute the largest integer value less than or equal to
 * @return the largest integer value less than or equal to the floating point number
 */
float floorf(float x) {
	return __builtin_floorf(x);
}

#endif
