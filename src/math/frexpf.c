
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: frexpf
//----------------------------------------------------------------------------*/
float frexpf(float x, int *exp) {
	return __builtin_frexpf(x, exp);
}
