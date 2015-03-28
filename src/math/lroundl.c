
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: lroundl
//----------------------------------------------------------------------------*/
long double lroundl(long double x) {
	return __builtin_lroundl(x);
}
