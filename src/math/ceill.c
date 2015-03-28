
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: ceill
//----------------------------------------------------------------------------*/
double ceill(double x) {
	return __builtin_ceill(x);
}
