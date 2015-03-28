
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: ilogb
//----------------------------------------------------------------------------*/
double ilogb(double x) {
	return __builtin_ilogb(x);
}
