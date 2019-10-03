
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: lround
//----------------------------------------------------------------------------*/
long int lround(double x) {
	return __builtin_lround(x);
}
