
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: log2f
//----------------------------------------------------------------------------*/
float log2f(float x) {
	return __builtin_log2f(x);
}
