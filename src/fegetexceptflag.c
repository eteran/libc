
#define __ELIBC_SOURCE
#include <fenv.h>

/*------------------------------------------------------------------------------
// Name: fetestexcept 
//----------------------------------------------------------------------------*/
int fegetexceptflag(fexcept_t *fp, int mask) {
	*fp = fetestexcept(mask);
	return 0;
}
