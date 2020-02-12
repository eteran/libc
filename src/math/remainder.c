
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: remainder
//----------------------------------------------------------------------------*/
double remainder(double x, double y) {
	return __builtin_remainder(x, y);
}

#endif
