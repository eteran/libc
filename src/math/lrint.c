
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: lrint
//----------------------------------------------------------------------------*/
long int lrint(double x) { return __builtin_lrint(x); }

#endif
