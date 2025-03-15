
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Decompose a floating-point number into its normalized fraction and exponent
 *
 * @param x the floating-point number to decompose
 * @param exp pointer to an integer where the exponent will be stored
 * @return the normalized fraction of the floating-point number
 */
long double frexpl(long double x, int *exp) {
	return __builtin_frexpl(x, exp);
}

#endif
