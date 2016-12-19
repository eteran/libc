
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: atanf
//----------------------------------------------------------------------------*/
float atanf(float x) {
	return __builtin_atanf(x);
}
