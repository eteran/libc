
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: modfl
//----------------------------------------------------------------------------*/
long double modfl(long double x, long double *iptr) {
	return __builtin_modfl(x, iptr);
}
