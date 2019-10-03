
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_expm1
//----------------------------------------------------------------------------*/
static double __elibc_expm1(double x) {
	return exp(x) - 1;
}

/*------------------------------------------------------------------------------
// Name: expm1
//----------------------------------------------------------------------------*/
double expm1(double x) {
	return __elibc_expm1(x);
}
