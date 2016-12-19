
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: acosf
//----------------------------------------------------------------------------*/
float acosf(float x) {
	return __builtin_acosf(x);
}
