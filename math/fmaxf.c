
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fmaxf
//----------------------------------------------------------------------------*/
float fmaxf(float x, float y) {
	return __builtin_fmaxf(x, y);
}
