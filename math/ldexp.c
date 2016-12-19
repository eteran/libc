
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: ldexp
//----------------------------------------------------------------------------*/
double ldexp(double x, int exp) {
	return __builtin_ldexp(x, exp);
}
