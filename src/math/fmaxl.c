
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fmaxl
//----------------------------------------------------------------------------*/
long double fmaxl(long double x, long double y) {
	return __builtin_fmaxl(x, y);
}
