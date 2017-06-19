
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: expl
//----------------------------------------------------------------------------*/
long double expl(long double x) {

#ifndef __FAST_MATH__
	if(isnan(x)) {
		return x;
	}

	if(isinf(x)) {
		if(x > 0.0) {
			return x;
		} else {
			return 0.0;
		}
	}

	/* TODO: handle underflow/overflow */
#endif

	return powl(M_E, x);
}
