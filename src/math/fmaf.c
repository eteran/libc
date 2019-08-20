
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fmaf
//----------------------------------------------------------------------------*/
float fmaf(float x, float y, float z) {
	// TODO(eteran): account for errors, and rounding mode
	return x * y * z;
}
