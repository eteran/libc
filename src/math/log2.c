
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: log2
//----------------------------------------------------------------------------*/
double log2(double x) {
	return __builtin_log2(x);
}
