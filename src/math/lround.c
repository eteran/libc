
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: lround
//----------------------------------------------------------------------------*/
double lround(double x) {
	return __builtin_lround(x);
}
