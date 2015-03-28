
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fmaf
//----------------------------------------------------------------------------*/
float fmaf(float x, float y, float z) {
	return __builtin_fmaf(x, y, z);
}
