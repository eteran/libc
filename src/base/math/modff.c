
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Split a floating point value into its integer and fractional parts
 *
 * @param arg the floating point value to split
 * @param iptr a pointer to store the integer part of the floating point value
 * @return the fractional part of the floating point value
 */
float modff(float arg, float *iptr) {
	return __builtin_modff(arg, iptr);
}

#endif
