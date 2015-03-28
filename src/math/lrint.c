
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: lrint
//----------------------------------------------------------------------------*/
double lrint(double x) {
	return __builtin_lrint(x);
}
