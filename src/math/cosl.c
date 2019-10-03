
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: cosl
//----------------------------------------------------------------------------*/
long double cosl(long double x) {
	return __builtin_cosl(x);
}
