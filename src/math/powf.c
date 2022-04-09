
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: powf
//----------------------------------------------------------------------------*/
float powf(float x, float y) {
	return __builtin_powf(x, y);
}

#endif
