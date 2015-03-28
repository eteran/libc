
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fmal
//----------------------------------------------------------------------------*/
long double fmal(long double x, long double y, long double z) {
	return __builtin_fmal(x, y, z);
}
