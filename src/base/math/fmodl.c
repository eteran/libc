
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the floating point remainder of the division operation x / y
 *
 * @param x the dividend
 * @param y the divisor
 * @return the remainder of the division
 * @note The returned value has the same sign as x and is less than y in magnitude.
 */
long double fmodl(long double x, long double y) {
	return __builtin_fmodl(x, y);
}

#endif
