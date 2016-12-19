
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: sinhl
//----------------------------------------------------------------------------*/
long double sinhl(long double x) {
	return __builtin_sinhl(x);
}
