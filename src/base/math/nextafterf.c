
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: nextafterf
//----------------------------------------------------------------------------*/
float nextafterf(float x, float y) {
	return __builtin_nextafterf(x, y);
}

#endif
