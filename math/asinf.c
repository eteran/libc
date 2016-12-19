
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: asinf
//----------------------------------------------------------------------------*/
float asinf(float x) {
	return __builtin_asinf(x);
}
