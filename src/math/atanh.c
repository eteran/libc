
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: atanh
//----------------------------------------------------------------------------*/
double atanh(double x) {
	return __builtin_atanh(x);
}

#endif
