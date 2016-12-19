
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: tgammaf
//----------------------------------------------------------------------------*/
float tgammaf(float x) {
	return __builtin_tgammaf(x);
}
