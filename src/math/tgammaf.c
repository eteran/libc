
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: tgammaf
//----------------------------------------------------------------------------*/
float tgammaf(float x) {
	return __builtin_tgammaf(x);
}

#endif
