
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Split a floating point value into its integer and fractional parts
 *
 * @param arg the floating point value to split
 * @param iptr a pointer to store the integer part of the floating point value
 * @return the fractional part of the floating point value
 */
long double modfl(long double arg, long double *iptr) {
	return __builtin_modfl(arg, iptr);
}

#endif
