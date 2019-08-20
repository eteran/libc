
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: expm1l
//----------------------------------------------------------------------------*/
long double expm1l(long double x) {
	return expl(x) - 1;
}
