
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: erfl
//----------------------------------------------------------------------------*/
long double erfl(long double x) {
	return __builtin_erfl(x);
}
