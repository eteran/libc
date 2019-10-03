
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: sinhl
//----------------------------------------------------------------------------*/
long double sinhl(long double x) {
	return __builtin_sinhl(x);
}
