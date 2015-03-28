
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: llroundl
//----------------------------------------------------------------------------*/
long double llroundl(long double x) {
	return __builtin_llroundl(x);
}
