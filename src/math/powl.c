
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: powl
//----------------------------------------------------------------------------*/
long double powl(long double x, long double y) {
	return __builtin_powl(x, y);
}
