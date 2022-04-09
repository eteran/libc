
#define __ELIBC_SOURCE
#include <fenv.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: fesetexceptflag
//----------------------------------------------------------------------------*/
int fesetexceptflag(const fexcept_t *fp, int mask) {
	assert(fp);
	feclearexcept(~*fp & mask);
	feraiseexcept(*fp & mask);
	return 0;
}
