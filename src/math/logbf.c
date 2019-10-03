
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: logbf
//----------------------------------------------------------------------------*/
float logbf(float x) {
	return __builtin_logbf(x);
}
