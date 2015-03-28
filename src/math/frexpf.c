
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: frexpf
//----------------------------------------------------------------------------*/
float frexpf(float x, int *exp) {
	return __builtin_frexpf(x, exp);
}
