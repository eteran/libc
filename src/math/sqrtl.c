
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: sqrtl
//----------------------------------------------------------------------------*/
long double sqrtl(long double x) {
	return __builtin_sqrtl(x);
}
