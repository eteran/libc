
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: llrintl
//----------------------------------------------------------------------------*/
long long int llrintl(long double x) { return __builtin_llrintl(x); }

#endif
