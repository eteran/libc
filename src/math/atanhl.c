
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: atanhl
//----------------------------------------------------------------------------*/
double atanhl(double x) {
	return __builtin_atanhl(x);
}
