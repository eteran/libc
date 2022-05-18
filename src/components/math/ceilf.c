
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: ceilf
//----------------------------------------------------------------------------*/
float ceilf(float x) {
	return __builtin_ceilf(x);
}

#endif
