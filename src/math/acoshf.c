
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: acoshf
//----------------------------------------------------------------------------*/
float acoshf(float x) {
	return __builtin_acoshf(x);
}
