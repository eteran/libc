
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: ilogbf
//----------------------------------------------------------------------------*/
int ilogbf(float x) {
	return __builtin_ilogbf(x);
}
