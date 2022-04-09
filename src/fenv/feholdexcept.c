
#define __ELIBC_SOURCE
#include <fenv.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: feholdexcept
//----------------------------------------------------------------------------*/
int feholdexcept(fenv_t *envp) {
	assert(envp);
	fegetenv(envp);
	feclearexcept(FE_ALL_EXCEPT);
	return 0;
}
