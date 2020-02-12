
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: rintl
//----------------------------------------------------------------------------*/
long double rintl(long double x) {
	return __builtin_rintl(x);
}

#endif
