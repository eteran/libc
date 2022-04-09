
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: logbl
//----------------------------------------------------------------------------*/
long double logbl(long double x) {
	return __builtin_logbl(x);
}

#endif
