
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: asinhf
//----------------------------------------------------------------------------*/
float asinhf(float x) {
	return __builtin_asinhf(x);
}
