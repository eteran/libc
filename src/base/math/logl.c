
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the natural logarithm of a floating point number
 *
 * @param x the floating point number to compute the natural logarithm of
 * @return the natural logarithm of the floating point number
 */
long double logl(long double x) {
	return __builtin_logl(x);
}

#endif
