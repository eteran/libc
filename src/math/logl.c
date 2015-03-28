
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: logl
//----------------------------------------------------------------------------*/
long double logl(long double x) {
	return __builtin_logl(x);
}
