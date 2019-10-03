
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: tgammaf
//----------------------------------------------------------------------------*/
float tgammaf(float x) {
	return __builtin_tgammaf(x);
}
