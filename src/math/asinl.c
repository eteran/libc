
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: asinl
//----------------------------------------------------------------------------*/
double asinl(double x) {
	return __builtin_asinl(x);
}
