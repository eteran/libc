
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: lgammaf
//----------------------------------------------------------------------------*/
float lgammaf(float x) {
	return __builtin_lgammaf(x);
}

#endif
