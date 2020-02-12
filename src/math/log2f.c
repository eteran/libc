
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: log2f
//----------------------------------------------------------------------------*/
float log2f(float x) {
	return __builtin_log2f(x);
}

#endif
