
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: hypot
//----------------------------------------------------------------------------*/
double hypot(double x, double y) {
	/* TODO(eteran): check for overflow */
	const double x2 = x * x;
	const double y2 = y * y;
	return sqrt(x2 + y2);
}
