
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fmal
//----------------------------------------------------------------------------*/
long double fmal(long double x, long double y, long double z) {
	// TODO(eteran): account for errors, and rounding mode
	return x * y * z;
}
