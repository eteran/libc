
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: ilogbf
//----------------------------------------------------------------------------*/
float ilogbf(float x) {
	return __builtin_ilogbf(x);
}
