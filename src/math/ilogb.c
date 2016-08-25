
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: ilogb
//----------------------------------------------------------------------------*/
int ilogb(double x) {
	return __builtin_ilogb(x);
}
