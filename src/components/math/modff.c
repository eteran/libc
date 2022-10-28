
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: modff
//----------------------------------------------------------------------------*/
float modff(float arg, float *iptr) {
	return __builtin_modff(arg, iptr);
}

#endif
