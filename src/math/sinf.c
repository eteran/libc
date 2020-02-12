
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: sinf
//----------------------------------------------------------------------------*/
float sinf(float x) {
	return (float)sin(x);
}

#endif
