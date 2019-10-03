
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: sqrtl
//----------------------------------------------------------------------------*/
long double sqrtl(long double x) {
	return __builtin_sqrtl(x);
}
