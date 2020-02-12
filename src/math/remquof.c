
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: remquof
//----------------------------------------------------------------------------*/
float remquof(float x, float y, int *quo) {
	return __builtin_remquof(x, y, quo);
}

#endif
