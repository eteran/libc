
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: sinf
//----------------------------------------------------------------------------*/
float sinf(float x) {
	return (float)sin(x);
}

#endif
