
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: atanhf
//----------------------------------------------------------------------------*/
float atanhf(float x) {
	return __builtin_atanhf(x);
}
