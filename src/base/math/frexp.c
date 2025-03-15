
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Decompose given floating point value x into a normalized fraction and an integral power of two.
 *
 * @param x the floating point number to decompose
 * @param exp pointer to an integer where the exponent will be stored
 * @return the normalized fraction of the floating point number
 */
double frexp(double x, int *exp) {
	return __builtin_frexp(x, exp);
}

#endif
