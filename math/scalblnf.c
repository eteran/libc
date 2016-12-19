
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: scalblnf
//----------------------------------------------------------------------------*/
float scalblnf(float x, long int exp) {
	return __builtin_scalblnf(x, exp);
}
