
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: ldexpf
//----------------------------------------------------------------------------*/
float ldexpf(float x, int exp) {
	return __builtin_ldexpf(x, exp);
}
