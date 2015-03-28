
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: rintf
//----------------------------------------------------------------------------*/
float rintf(float x) {
	return __builtin_rintf(x);
}
