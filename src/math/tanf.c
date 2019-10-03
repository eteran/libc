
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: tanf
//----------------------------------------------------------------------------*/
float tanf(float x) {
	return __builtin_tanf(x);
}
