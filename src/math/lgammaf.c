
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: lgammaf
//----------------------------------------------------------------------------*/
float lgammaf(float x) {
	return __builtin_lgammaf(x);
}
