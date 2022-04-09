
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: log10f
//----------------------------------------------------------------------------*/
float log10f(float x) {
	return __builtin_log10f(x);
}

#endif
