
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_fma
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static double __elibc_fma(double x, double y, double z) {
	/* TODO(eteran): account for errors, and rounding mode */
	return x * y * z;
}

/*------------------------------------------------------------------------------
// Name: fma
//----------------------------------------------------------------------------*/
double fma(double x, double y, double z) {
	return __elibc_fma(x, y, z);
}

#endif
