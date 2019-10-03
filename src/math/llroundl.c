
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: llroundl
//----------------------------------------------------------------------------*/
long long int llroundl(long double x) {
	return __builtin_llroundl(x);
}
