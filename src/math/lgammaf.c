
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: lgammaf
//----------------------------------------------------------------------------*/
float lgammaf(float x) {
	return __builtin_lgammaf(x);
}
