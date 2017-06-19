
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fminl
//----------------------------------------------------------------------------*/
long double fminl(long double x, long double y) {
#ifndef __FAST_MATH__
	if(isnan(x)) {
		return y;
	}

	if(isnan(y)) {
		return x;
	}
#endif
	return x < y ? x : y;
}
