
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: llrint
//----------------------------------------------------------------------------*/
long long int llrint(double x) { return __builtin_llrint(x); }

#endif
