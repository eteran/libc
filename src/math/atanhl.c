
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: atanhl
//----------------------------------------------------------------------------*/
long double atanhl(long double x) {
	return __builtin_atanhl(x);
}
