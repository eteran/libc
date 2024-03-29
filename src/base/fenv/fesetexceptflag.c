
#define _ELIBC_SOURCE
#include <assert.h>
#include <fenv.h>

/*------------------------------------------------------------------------------
// Name: fesetexceptflag
//----------------------------------------------------------------------------*/
int fesetexceptflag(const fexcept_t *fp, int mask) {
	assert(fp);
	feclearexcept(~*fp & mask);
	feraiseexcept(*fp & mask);
	return 0;
}
