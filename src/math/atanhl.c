
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: atanhl
//----------------------------------------------------------------------------*/
long double atanhl(long double x) {
	return __builtin_atanhl(x);
}
