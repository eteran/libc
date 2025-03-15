
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the integer value of the exponent of a floating-point value
 *
 * @param x the floating-point value to compute the exponent of
 * @return the integer value of the exponent
 */
int ilogbf(float x) {
	return __builtin_ilogbf(x);
}

#endif
