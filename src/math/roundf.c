
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: roundf
//----------------------------------------------------------------------------*/
float roundf(float x) {
	return __builtin_roundf(x);
}

#endif
