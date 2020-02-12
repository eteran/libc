
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: scalbln
//----------------------------------------------------------------------------*/
double scalbln(double x, long int exp) {
	return __builtin_scalbln(x, exp);
}

#endif
