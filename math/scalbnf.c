
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: scalbnf
//----------------------------------------------------------------------------*/
float scalbnf(float x, int exp) {
	return __builtin_scalbnf(x, exp);
}
