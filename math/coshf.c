
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: coshf
//----------------------------------------------------------------------------*/
float coshf(float x) {
	return __builtin_coshf(x);
}
