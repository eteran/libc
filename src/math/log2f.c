
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: log2f
//----------------------------------------------------------------------------*/
float log2f(float x) {
	return __builtin_log2f(x);
}
