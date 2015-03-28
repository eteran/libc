
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fminl
//----------------------------------------------------------------------------*/
long double fminl(long double x, long double y) {
	return __builtin_fminl(x, y);
}
