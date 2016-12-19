
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: atan2f
//----------------------------------------------------------------------------*/
float atan2f(float x, float y) {
	return __builtin_atan2f(x, y);
}
