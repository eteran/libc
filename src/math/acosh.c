
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: acosh
//----------------------------------------------------------------------------*/
double acosh(double x) {
	return __builtin_acosh(x);
}

#endif
