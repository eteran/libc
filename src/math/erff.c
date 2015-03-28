
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: erff
//----------------------------------------------------------------------------*/
float erff(float x) {
	return __builtin_erff(x);
}
