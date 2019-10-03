
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: nextafterf
//----------------------------------------------------------------------------*/
float nextafterf(float x, float y) {
	return __builtin_nextafterf(x, y);
}
