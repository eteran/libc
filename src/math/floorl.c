
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: floorl
//----------------------------------------------------------------------------*/
long double floorl(long double x) {
	return __builtin_floorl(x);
}
