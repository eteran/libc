
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: lrintl
//----------------------------------------------------------------------------*/
long int lrintl(long double x) {
	return __builtin_lrintl(x);
}

#endif
