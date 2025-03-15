
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Round a double to the nearest integer value as a long long int
 *
 * @param x the double to round
 * @return the rounded value
 */
long long int llround(double x) {
	return __builtin_llround(x);
}

#endif
