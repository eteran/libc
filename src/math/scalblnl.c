
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: scalblnl
//----------------------------------------------------------------------------*/
long double scalblnl(long double x, long int exp) {
	return __builtin_scalblnl(x, exp);
}
