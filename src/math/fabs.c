
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_fabs
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE static double __elibc_fabs(double x) {
	return __builtin_fabs(x);
}

/*------------------------------------------------------------------------------
// Name: fabs
//----------------------------------------------------------------------------*/
double fabs(double x) {
	return __elibc_fabs(x);
}

#endif
