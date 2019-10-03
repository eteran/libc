
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fminl
//----------------------------------------------------------------------------*/
static long double __elibc_fminl(long double x, long double y) {
	return x < y ? x : y;
}

/*------------------------------------------------------------------------------
// Name: fminl
//----------------------------------------------------------------------------*/
long double fminl(long double x, long double y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return y;
	}

	if (isnan(y)) {
		return x;
	}
#endif
	return __elibc_fminl(x, y);
}
