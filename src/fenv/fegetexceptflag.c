
#define __ELIBC_SOURCE
#include <fenv.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: fetestexcept
//----------------------------------------------------------------------------*/
int fegetexceptflag(fexcept_t *fp, int mask) {
	assert(fp);
	*fp = fetestexcept(mask);
	return 0;
}
