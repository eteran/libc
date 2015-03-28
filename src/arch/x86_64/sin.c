
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: sin
//----------------------------------------------------------------------------*/
double sin(double x) {
    double value;

#ifndef __FAST_MATH__
#if 0
	if(isnan(x)) {
		return x;
	}
	
	if(isinf(x)) {
		errno = EDOM;
		return NAN;
	}
#endif
#endif
	
    __asm__ __volatile__ ("fsin" : "=t" (value) : "0" (x));
    return value;
}
