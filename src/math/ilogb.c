
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: ilogb
//----------------------------------------------------------------------------*/
int ilogb(double x) {
	return __builtin_ilogb(x);
}

#endif
