
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: expl
//----------------------------------------------------------------------------*/
long double expl(long double x) {
	return __builtin_expl(x);
}
