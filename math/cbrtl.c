
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: cbrtl
//----------------------------------------------------------------------------*/
long double cbrtl(long double x) {
	return __builtin_cbrtl(x);
}
