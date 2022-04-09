
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: erfcf
//----------------------------------------------------------------------------*/
float erfcf(float x) {
	return __builtin_erfcf(x);
}

#endif
