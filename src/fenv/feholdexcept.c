
#define __ELIBC_SOURCE
#include <fenv.h>

/*------------------------------------------------------------------------------
// Name: feholdexcept 
//----------------------------------------------------------------------------*/
int feholdexcept(fenv_t *envp) {
	fegetenv(envp);
	feclearexcept(FE_ALL_EXCEPT);
	return 0;
}
