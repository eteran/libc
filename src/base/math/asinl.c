
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: asinl
//----------------------------------------------------------------------------*/
long double asinl(long double x) {
	return __builtin_asinl(x);
}

#endif
