
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: erfcl
//----------------------------------------------------------------------------*/
long double erfcl(long double x) {
	return __builtin_erfcl(x);
}
