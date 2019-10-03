
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: ilogbf
//----------------------------------------------------------------------------*/
int ilogbf(float x) {
	return __builtin_ilogbf(x);
}
