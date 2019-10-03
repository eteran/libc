
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: frexp
//----------------------------------------------------------------------------*/
double frexp(double x, int *exp) {
	return __builtin_frexp(x, exp);
}
