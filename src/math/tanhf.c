
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: tanhf
//----------------------------------------------------------------------------*/
float tanhf(float x) {
	return __builtin_tanhf(x);
}

#endif
