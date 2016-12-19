
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: nextafter
//----------------------------------------------------------------------------*/
double nextafter(double x, double y) {
	return __builtin_nextafter(x, y);
}
