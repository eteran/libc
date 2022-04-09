
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: acosl
//----------------------------------------------------------------------------*/
long double acosl(long double x) {
	return __builtin_acosl(x);
}

#endif
