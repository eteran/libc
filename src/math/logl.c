
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: logl
//----------------------------------------------------------------------------*/
long double logl(long double x) {
	return __builtin_logl(x);
}

#endif
