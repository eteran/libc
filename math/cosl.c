
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: cosl
//----------------------------------------------------------------------------*/
long double cosl(long double x) {
	return __builtin_cosl(x);
}
