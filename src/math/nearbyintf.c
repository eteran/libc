
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: nearbyintf
//----------------------------------------------------------------------------*/
float nearbyintf(float x) {
	return __builtin_nearbyintf(x);
}
