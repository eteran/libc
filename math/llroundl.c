
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: llroundl
//----------------------------------------------------------------------------*/
long long int llroundl(long double x) {
	return __builtin_llroundl(x);
}
