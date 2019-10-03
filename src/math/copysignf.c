
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: copysignf
//----------------------------------------------------------------------------*/
float copysignf(float x, float y) {
	return __builtin_copysignf(x, y);
}
