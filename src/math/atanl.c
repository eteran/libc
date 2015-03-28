
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: atanl
//----------------------------------------------------------------------------*/
double atanl(double x) {
	return __builtin_atanl(x);
}
