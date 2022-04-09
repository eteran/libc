
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: remquol
//----------------------------------------------------------------------------*/
long double remquol(long double x, long double y, int *quo) {
	return __builtin_remquol(x, y, quo);
}

#endif
