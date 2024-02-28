
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: sqrtl
//----------------------------------------------------------------------------*/
long double sqrtl(long double x) {
	return __builtin_sqrtl(x);
}

#endif
