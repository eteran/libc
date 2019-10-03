
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: hypot
//----------------------------------------------------------------------------*/
static double __elibc_hypot(double x, double y) {
	/* TODO(eteran): check for overflow */
	const double x2 = x * x;
	const double y2 = y * y;
	return sqrt(x2 + y2);
}

/*------------------------------------------------------------------------------
// Name: hypot
//----------------------------------------------------------------------------*/
double hypot(double x, double y) {
	return __elibc_hypot(x, y);
}
