
#define __ELIBC_SOURCE
#include <fenv.h>

/*------------------------------------------------------------------------------
// Name: fesetexceptflag 
//----------------------------------------------------------------------------*/
int fesetexceptflag(const fexcept_t *fp, int mask) {
	feclearexcept(~*fp & mask);
	feraiseexcept(*fp & mask);
	return 0;
}
