
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: scalbnl
//----------------------------------------------------------------------------*/
long double scalbnl(long double x, int exp) {
	return __builtin_scalbnl(x, exp);
}

#endif
