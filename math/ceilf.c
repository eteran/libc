
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: ceilf
//----------------------------------------------------------------------------*/
float ceilf(float x) {
	return __builtin_ceilf(x);
}
