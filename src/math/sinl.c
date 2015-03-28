
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: sinl
//----------------------------------------------------------------------------*/
long double sinl(long double x) {
	return __builtin_sinl(x);
}
