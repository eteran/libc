
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: expf
//----------------------------------------------------------------------------*/
float expf(float x) {
	return __builtin_expf(x);
}
