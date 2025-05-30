
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the complementary error function of a floating point number
 *
 * @param x the floating point number to compute the complementary error function of
 * @return the complementary error function of the floating point number
 */
double erfc(double x) {
	return __builtin_erfc(x);
}

#endif
