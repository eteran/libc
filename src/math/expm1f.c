
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: expm1f
//----------------------------------------------------------------------------*/
float expm1f(float x) {
	return __builtin_expm1f(x);
}
