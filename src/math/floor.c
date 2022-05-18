
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_floor
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE static double __elibc_floor(double x) {
	return __builtin_floor(x);
}

/*------------------------------------------------------------------------------
// Name: floor
//----------------------------------------------------------------------------*/
double floor(double x) {
	return __elibc_floor(x);
}

#endif
