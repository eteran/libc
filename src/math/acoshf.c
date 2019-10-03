
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: acoshf
//----------------------------------------------------------------------------*/
float acoshf(float x) {
	return __builtin_acoshf(x);
}
