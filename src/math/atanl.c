
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: atanl
//----------------------------------------------------------------------------*/
long double atanl(long double x) {
	return __builtin_atanl(x);
}
