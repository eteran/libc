
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: atanhf
//----------------------------------------------------------------------------*/
float atanhf(float x) {
	return __builtin_atanhf(x);
}

#endif
