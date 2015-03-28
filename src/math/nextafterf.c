
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: nextafterf
//----------------------------------------------------------------------------*/
float nextafterf(float x, float y) {
	return __builtin_nextafterf(x, y);
}
