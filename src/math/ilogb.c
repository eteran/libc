
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: ilogb
//----------------------------------------------------------------------------*/
int ilogb(double x) {
	return __builtin_ilogb(x);
}
