
#define _ELIBC_SOURCE
#include <assert.h>
#include <fenv.h>

/*------------------------------------------------------------------------------
// Name: fetestexcept
//----------------------------------------------------------------------------*/
int fegetexceptflag(fexcept_t *fp, int mask) {
	assert(fp);
	*fp = fetestexcept(mask);
	return 0;
}
