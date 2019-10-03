
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: ceilf
//----------------------------------------------------------------------------*/
float ceilf(float x) {
	return __builtin_ceilf(x);
}
