
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: tgammal
//----------------------------------------------------------------------------*/
long double tgammal(long double x) {
	return __builtin_tgammal(x);
}
