
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: lgammal
//----------------------------------------------------------------------------*/
long double lgammal(long double x) {
	return __builtin_lgammal(x);
}
