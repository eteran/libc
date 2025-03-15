
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the sine of a floating point number
 *
 * @param x the floating point number to compute the sine of
 * @return the sine of the floating point number
 */
float sinf(float x) {
	return (float)sin(x);
}

#endif
