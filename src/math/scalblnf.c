
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: scalblnf
//----------------------------------------------------------------------------*/
float scalblnf(float x, long int exp) {
	return __builtin_scalblnf(x, exp);
}

#endif
