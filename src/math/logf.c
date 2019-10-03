
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: logf
//----------------------------------------------------------------------------*/
float logf(float x) {
	return __builtin_logf(x);
}
