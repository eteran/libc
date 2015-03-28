
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: nearbyintf
//----------------------------------------------------------------------------*/
float nearbyintf(float x) {
	return __builtin_nearbyintf(x);
}
