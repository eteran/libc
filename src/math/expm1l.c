
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_expm1l
//----------------------------------------------------------------------------*/
static long double __elibc_expm1l(long double x) {
	return expl(x) - 1;
}

/*------------------------------------------------------------------------------
// Name: expm1l
//----------------------------------------------------------------------------*/
long double expm1l(long double x) {
	return __elibc_expm1l(x);
}

#endif
