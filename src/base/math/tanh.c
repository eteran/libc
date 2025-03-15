
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the hyperbolic tangent of a floating point number
 *
 * @param x the floating point number to compute the hyperbolic tangent of
 * @return the hyperbolic tangent of the floating point number
 */
double tanh(double x) {

#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 0.0 || x == -0.0) {
		return x;
	}

	if (isinf(x)) {
		return copysign(1, x);
	}
#endif

	return sinh(x) / cosh(x);
}

#endif
