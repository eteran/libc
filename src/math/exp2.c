
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: exp2
//----------------------------------------------------------------------------*/
double exp2(double x) {
	return __builtin_exp2(x);
}
