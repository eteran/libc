
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: llrintf
//----------------------------------------------------------------------------*/
long long int llrintf(float x) {
	return __builtin_llrintf(x);
}
