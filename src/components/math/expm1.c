
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_expm1
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static double __elibc_expm1(double x) {
	return exp(x) - 1;
}

/*------------------------------------------------------------------------------
// Name: expm1
//----------------------------------------------------------------------------*/
double expm1(double x) {
	return __elibc_expm1(x);
}

#endif
