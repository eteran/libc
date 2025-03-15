
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Round floating-point value to the nearest integer value as a long long int
 *
 * @param x the long double to round
 * @return the rounded value
 */
long long int llrintl(long double x) {
	return __builtin_llrintl(x);
}

#endif
