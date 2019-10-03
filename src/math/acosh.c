
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: acosh
//----------------------------------------------------------------------------*/
double acosh(double x) {
	return __builtin_acosh(x);
}
