
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: acosh
//----------------------------------------------------------------------------*/
double acosh(double x) {
	return __builtin_acosh(x);
}
