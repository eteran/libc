
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: cbrt
//----------------------------------------------------------------------------*/
double cbrt(double x) {
	return __builtin_cbrt(x);
}

#endif
