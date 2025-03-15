
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the value of a floating point number multiplied by FLT_RADIX raised to the power of exp
 *
 * @param x the floating point number to compute the value of
 * @param exp the exponent to raise 2 to
 * @return the value of the floating point number multiplied by FLT_RADIX raised to the power of exp
 */
long double scalbnl(long double x, int exp) {
	return __builtin_scalbnl(x, exp);
}

#endif
