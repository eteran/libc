
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fmaf
//----------------------------------------------------------------------------*/
static float __elibc_fmaf(float x, float y, float z) {
	/* TODO(eteran): account for errors, and rounding mode */
	return x * y * z;
}

/*------------------------------------------------------------------------------
// Name: fmaf
//----------------------------------------------------------------------------*/
float fmaf(float x, float y, float z) {
	return __elibc_fmaf(x, y, z);
}
