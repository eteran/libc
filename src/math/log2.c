
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: log2
//----------------------------------------------------------------------------*/
double log2(double x) {
	return __builtin_log2(x);
}
