
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_expm1f
//----------------------------------------------------------------------------*/
static float __elibc_expm1f(float x) {
	return expf(x) - 1;
}

/*------------------------------------------------------------------------------
// Name: expm1f
//----------------------------------------------------------------------------*/
float expm1f(float x) {
	return __elibc_expm1f(x);
}

#endif
