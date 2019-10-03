
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: nexttoward
//----------------------------------------------------------------------------*/
double nexttoward(double x, long double y) {
	return __builtin_nexttoward(x, y);
}
