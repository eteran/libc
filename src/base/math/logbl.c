
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Extracts the value of the unbiased radix-independent
 * exponent from the floating point argument x, and returns it as a floating point value.
 *
 * @param x the floating point value to get the exponent of
 * @return the exponent of the floating point value
 */
long double logbl(long double x) {
	return __builtin_logbl(x);
}

#endif
