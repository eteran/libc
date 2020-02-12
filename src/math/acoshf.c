
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: acoshf
//----------------------------------------------------------------------------*/
float acoshf(float x) {
	return __builtin_acoshf(x);
}

#endif
