
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: remquo
//----------------------------------------------------------------------------*/
double remquo(double x, double y, int *quo) {
	return __builtin_remquo(x, y, quo);
}
