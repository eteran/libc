
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: erfcl
//----------------------------------------------------------------------------*/
long double erfcl(long double x) {
	return __builtin_erfcl(x);
}
