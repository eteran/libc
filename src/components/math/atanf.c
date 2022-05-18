
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: atanf
//----------------------------------------------------------------------------*/
float atanf(float x) {
	return __builtin_atanf(x);
}

#endif
