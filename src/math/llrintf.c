
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: llrintf
//----------------------------------------------------------------------------*/
long long int llrintf(float x) {
	return __builtin_llrintf(x);
}
