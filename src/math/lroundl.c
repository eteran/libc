
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: lroundl
//----------------------------------------------------------------------------*/
long int lroundl(long double x) {
	return __builtin_lroundl(x);
}

#endif
