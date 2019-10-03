
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fma
//----------------------------------------------------------------------------*/
static double __elibc_fma(double x, double y, double z) {
	return x * y * z;
}

/*------------------------------------------------------------------------------
// Name: fma
//----------------------------------------------------------------------------*/
double fma(double x, double y, double z) {
	// TODO(eteran): account for errors, and rounding mode
	return __elibc_fma(x, y, z);
}
