
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: log10f
//----------------------------------------------------------------------------*/
float log10f(float x) {
	return __builtin_log10f(x);
}
