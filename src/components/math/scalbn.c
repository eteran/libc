
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: scalbn
//----------------------------------------------------------------------------*/
double scalbn(double x, int exp) {
	return __builtin_scalbn(x, exp);
}

#endif
