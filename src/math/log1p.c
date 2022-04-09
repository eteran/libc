
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: log1p
//----------------------------------------------------------------------------*/
double log1p(double x) {
	return __builtin_log1p(x);
}

#endif
