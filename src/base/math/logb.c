
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Extracts the value of the unbiased radix-independent
 * exponent from the floating point argument x, and returns it as a floating point value.
 *
 * @param x the floating point value to get the exponent of
 * @return the exponent of the floating point value
 */
double logb(double x) {
	return __builtin_logb(x);
}

#endif
