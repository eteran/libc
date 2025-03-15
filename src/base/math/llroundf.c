
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Round a float to the nearest integer value as a long long int
 *
 * @param x the float to round
 * @return the rounded value
 */
long long int llroundf(float x) {
	return __builtin_llroundf(x);
}

#endif
