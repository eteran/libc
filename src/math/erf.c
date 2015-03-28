
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: erf
//----------------------------------------------------------------------------*/
float erf(float x) {
	return __builtin_erf(x);
}
