
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fdiml
//----------------------------------------------------------------------------*/
long double fdiml(long double x, long double y) {
	return __builtin_fdiml(x, y);
}
