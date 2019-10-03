
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: floorl
//----------------------------------------------------------------------------*/
long double floorl(long double x) {
	return __builtin_floorl(x);
}
