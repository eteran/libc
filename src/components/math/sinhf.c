
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: sinhf
//----------------------------------------------------------------------------*/
float sinhf(float x) {
	return __builtin_sinhf(x);
}

#endif
