
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: nextafter
//----------------------------------------------------------------------------*/
double nextafter(double x, double y) {
	return __builtin_nextafter(x, y);
}
