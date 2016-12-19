
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: frexp
//----------------------------------------------------------------------------*/
double frexp(double x, int *exp) {
	return __builtin_frexp(x, exp);
}
