
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: cbrtl
//----------------------------------------------------------------------------*/
long double cbrtl(long double x) {
	return __builtin_cbrtl(x);
}

#endif
