
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: sqrtf
//----------------------------------------------------------------------------*/
float sqrtf(float x) {
	return __builtin_sqrtf(x);
}
