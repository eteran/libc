
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: nexttoward
//----------------------------------------------------------------------------*/
double nexttoward(double x, double y) {
	return __builtin_nexttoward(x, y);
}
