
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: truncl
//----------------------------------------------------------------------------*/
long double truncl(long double x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 0.0 || x == -0.0) {
		return x;
	}

	if (isinf(x)) {
		return x;
	}
#endif

	return __builtin_truncl(x);
}
