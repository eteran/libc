
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: logf
//----------------------------------------------------------------------------*/
float logf(float x) {
	return __builtin_logf(x);
}
