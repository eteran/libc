
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_expl
//----------------------------------------------------------------------------*/
static long double __elibc_expl(long double x) {
	return powl(M_E, x);
}

/*------------------------------------------------------------------------------
// Name: expl
//----------------------------------------------------------------------------*/
long double expl(long double x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (isinf(x)) {
		if (x > 0.0) {
			return x;
		} else {
			return 0.0;
		}
	}

	/* TODO(eteran): handle underflow/overflow */
#endif

	return __elibc_expl(x);
}
