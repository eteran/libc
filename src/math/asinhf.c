
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: asinhf
//----------------------------------------------------------------------------*/
float asinhf(float x) {
	return __builtin_asinhf(x);
}

#endif
