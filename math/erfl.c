
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: erfl
//----------------------------------------------------------------------------*/
long double erfl(long double x) {
	return __builtin_erfl(x);
}
