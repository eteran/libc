
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: llrintf
//----------------------------------------------------------------------------*/
float llrintf(float x) {
	return __builtin_llrintf(x);
}
