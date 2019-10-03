
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: logl
//----------------------------------------------------------------------------*/
long double logl(long double x) {
	return __builtin_logl(x);
}
