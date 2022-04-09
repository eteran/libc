
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: llroundf
//----------------------------------------------------------------------------*/
long long int llroundf(float x) {
	return __builtin_llroundf(x);
}

#endif
