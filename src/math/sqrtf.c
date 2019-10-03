
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: sqrtf
//----------------------------------------------------------------------------*/
float sqrtf(float x) {
	return __builtin_sqrtf(x);
}
