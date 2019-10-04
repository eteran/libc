
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fmal
//----------------------------------------------------------------------------*/
static long double __elibc_fmal(long double x, long double y, long double z) {
	/* TODO(eteran): account for errors, and rounding mode */
	return x * y * z;
}

/*------------------------------------------------------------------------------
// Name: fmal
//----------------------------------------------------------------------------*/
long double fmal(long double x, long double y, long double z) {
	return __elibc_fmal(x, y, z);
}
