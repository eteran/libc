
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: scalbn
//----------------------------------------------------------------------------*/
double scalbn(double x, int exp) {
	return __builtin_scalbn(x, exp);
}
