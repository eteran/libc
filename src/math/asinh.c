
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: asinh
//----------------------------------------------------------------------------*/
double asinh(double x) {
	return __builtin_asinh(x);
}

#endif
