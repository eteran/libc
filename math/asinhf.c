
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: asinhf
//----------------------------------------------------------------------------*/
float asinhf(float x) {
	return __builtin_asinhf(x);
}
