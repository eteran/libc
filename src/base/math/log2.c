
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: log2
//----------------------------------------------------------------------------*/
double log2(double x) {
	return __builtin_log2(x);
}

#endif
