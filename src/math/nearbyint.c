
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: nearbyint
//----------------------------------------------------------------------------*/
double nearbyint(double x) {
	return __builtin_nearbyint(x);
}

#endif
