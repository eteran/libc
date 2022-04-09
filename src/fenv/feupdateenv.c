
#define __ELIBC_SOURCE
#include <fenv.h>
#include <assert.h>

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
