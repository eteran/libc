
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: log2l
//----------------------------------------------------------------------------*/
long double log2l(long double x) {
	return __builtin_log2l(x);
}
