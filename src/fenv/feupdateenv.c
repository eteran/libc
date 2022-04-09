
#define __ELIBC_SOURCE
#include <assert.h>
#include <fenv.h>

/*------------------------------------------------------------------------------
// Name: feupdateenv
//----------------------------------------------------------------------------*/
int feupdateenv(const fenv_t *envp) {
	const int ex = fetestexcept(FE_ALL_EXCEPT);
	assert(envp);
	fesetenv(envp);
	feraiseexcept(ex);
	return 0;
}
