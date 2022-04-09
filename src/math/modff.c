
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: modff
//----------------------------------------------------------------------------*/
float modff(float x, float *iptr) {
	return __builtin_modff(x, iptr);
}

#endif
