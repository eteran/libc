
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: logbf
//----------------------------------------------------------------------------*/
float logbf(float x) {
	return __builtin_logbf(x);
}
