
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: lrintl
//----------------------------------------------------------------------------*/
long int lrintl(long double x) {
	return __builtin_lrintl(x);
}
