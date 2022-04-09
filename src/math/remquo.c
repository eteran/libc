
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: remquo
//----------------------------------------------------------------------------*/
double remquo(double x, double y, int *quo) {
	return __builtin_remquo(x, y, quo);
}

#endif
