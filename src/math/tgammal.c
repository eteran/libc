
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: tgammal
//----------------------------------------------------------------------------*/
long double tgammal(long double x) {
	return __builtin_tgammal(x);
}
