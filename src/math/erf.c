
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: erf
//----------------------------------------------------------------------------*/
double erf(double x) {
	return __builtin_erf(x);
}

#endif
