
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: atanl
//----------------------------------------------------------------------------*/
long double atanl(long double x) {
	return __builtin_atanl(x);
}
