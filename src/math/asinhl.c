
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: asinhl
//----------------------------------------------------------------------------*/
double asinhl(double x) {
	return __builtin_asinhl(x);
}
