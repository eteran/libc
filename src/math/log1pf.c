
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: log1pf
//----------------------------------------------------------------------------*/
float log1pf(float x) {
	return __builtin_log1pf(x);
}
