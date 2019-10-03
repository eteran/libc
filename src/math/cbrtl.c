
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: cbrtl
//----------------------------------------------------------------------------*/
long double cbrtl(long double x) {
	return __builtin_cbrtl(x);
}
