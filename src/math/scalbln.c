
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: scalbln
//----------------------------------------------------------------------------*/
double scalbln(double x, long int exp) {
	return __builtin_scalbln(x, exp);
}

#endif
