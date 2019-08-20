
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: expf
//----------------------------------------------------------------------------*/
float expf(float x) {

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

	/* TODO(eteran): handle underflow/overflow */
#endif

	return powf(M_E, x);
}
