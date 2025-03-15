
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the error function of a floating point number
 *
 * @param x the floating point number to compute the error function of
 * @return the error function of the floating point number
 */
float erff(float x) {
	return __builtin_erff(x);
}

#endif
