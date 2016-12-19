
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: exp2f
//----------------------------------------------------------------------------*/
float exp2f(float x) {
	return __builtin_exp2f(x);
}
