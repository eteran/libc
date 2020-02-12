
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: remquof
//----------------------------------------------------------------------------*/
float remquof(float x, float y, int *quo) {
	return __builtin_remquof(x, y, quo);
}

#endif
