
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_ceil
//----------------------------------------------------------------------------*/
_ENSURE_INLINE static double __elibc_ceil(double x) {
	return __builtin_ceil(x);
}

/*------------------------------------------------------------------------------
// Name: ceil
//----------------------------------------------------------------------------*/
double ceil(double x) {
	return __elibc_ceil(x);
}

#endif
