
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: erff
//----------------------------------------------------------------------------*/
float erff(float x) {
	return __builtin_erff(x);
}
