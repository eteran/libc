
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: acoshl
//----------------------------------------------------------------------------*/
double acoshl(double x) {
	return __builtin_acoshl(x);
}
