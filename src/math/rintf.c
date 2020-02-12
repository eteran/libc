
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: rintf
//----------------------------------------------------------------------------*/
float rintf(float x) {
	return __builtin_rintf(x);
}

#endif
