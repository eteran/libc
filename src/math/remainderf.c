
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: remainderf
//----------------------------------------------------------------------------*/
float remainderf(float x, float y) {
	return __builtin_remainderf(x, y);
}
