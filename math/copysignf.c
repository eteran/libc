
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: copysignf
//----------------------------------------------------------------------------*/
float copysignf(float x, float y) {
	return __builtin_copysignf(x, y);
}
