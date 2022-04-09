
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: tanl
//----------------------------------------------------------------------------*/
long double tanl(long double x) {
	return __builtin_tanl(x);
}

#endif
