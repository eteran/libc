
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: frexpf
//----------------------------------------------------------------------------*/
float frexpf(float x, int *exp) {
	return __builtin_frexpf(x, exp);
}

#endif
