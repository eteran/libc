
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: lround
//----------------------------------------------------------------------------*/
long int lround(double x) {
	return __builtin_lround(x);
}
