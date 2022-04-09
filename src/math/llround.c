
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: llround
//----------------------------------------------------------------------------*/
long long int llround(double x) {
	return __builtin_llround(x);
}

#endif
