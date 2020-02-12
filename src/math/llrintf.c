
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: llrintf
//----------------------------------------------------------------------------*/
long long int llrintf(float x) {
	return __builtin_llrintf(x);
}

#endif
