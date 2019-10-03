
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: lgammal
//----------------------------------------------------------------------------*/
long double lgammal(long double x) {
	return __builtin_lgammal(x);
}
