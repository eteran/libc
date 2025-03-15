
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Extract the value of the unbiased exponent from the floating point argument arg,
 * and returns it as a signed integer value.
 *
 * @param x The floating point argument.
 * @return The value of the unbiased exponent.
 */
int ilogbf(float x) {
	return __builtin_ilogbf(x);
}

#endif
