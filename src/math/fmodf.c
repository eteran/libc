
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: fmodf
//----------------------------------------------------------------------------*/
float fmodf(float x, float y) {
	return __builtin_fmodf(x, y);
}

#endif
