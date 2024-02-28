
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: log2l
//----------------------------------------------------------------------------*/
long double log2l(long double x) {
	return __builtin_log2l(x);
}

#endif
