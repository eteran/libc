
#define _ELIBC_SOURCE
#include <assert.h>
#include <fenv.h>

/*------------------------------------------------------------------------------
// Name: feholdexcept
//----------------------------------------------------------------------------*/
int feholdexcept(fenv_t *envp) {
	assert(envp);
	fegetenv(envp);
	feclearexcept(FE_ALL_EXCEPT);
	return 0;
}
