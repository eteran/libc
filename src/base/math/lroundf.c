
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: lroundf
//----------------------------------------------------------------------------*/
long int lroundf(float x) {
	return __builtin_lroundf(x);
}

#endif
