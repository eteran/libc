
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: remainderf
//----------------------------------------------------------------------------*/
float remainderf(float x, float y) {
	return __builtin_remainderf(x, y);
}

#endif
