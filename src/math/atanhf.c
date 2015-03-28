
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: atanhf
//----------------------------------------------------------------------------*/
float atanhf(float x) {
	return __builtin_atanhf(x);
}
