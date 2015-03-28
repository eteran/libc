
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: tanf
//----------------------------------------------------------------------------*/
float tanf(float x) {
	return __builtin_tanf(x);
}
