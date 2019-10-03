
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: atanf
//----------------------------------------------------------------------------*/
float atanf(float x) {
	return __builtin_atanf(x);
}
