
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the next representable floating point value towards y
 *
 * @param x the floating point value to compute the next value of
 * @param y the value to compute the next value towards
 * @return the next representable floating point value towards y
 */
float nexttowardf(float x, long double y) {
	return __builtin_nexttowardf(x, y);
}

#endif
