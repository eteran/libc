
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the integer value of the exponent of a floating-point value
 *
 * @param x
 * @return
 */
int ilogbl(long double x) {
	return __builtin_ilogbl(x);
}

#endif
