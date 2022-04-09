
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: erfcl
//----------------------------------------------------------------------------*/
long double erfcl(long double x) {
	return __builtin_erfcl(x);
}

#endif
