
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: log2l
//----------------------------------------------------------------------------*/
long double log2l(long double x) {
	return __builtin_log2l(x);
}
