
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: acosl
//----------------------------------------------------------------------------*/
double acosl(double x) {
	return __builtin_acosl(x);
}
