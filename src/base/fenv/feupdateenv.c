
#define _ELIBC_SOURCE
#include <assert.h>
#include <fenv.h>

/**
 * @brie f Updates the floating-point environment with the values stored in the given object.
 *
 * @param envp A pointer to the object containing the floating-point environment to set.
 * @return Returns 0 on success, or a non-zero value if an error occurs.
 */
int feupdateenv(const fenv_t *envp) {
	const int ex = fetestexcept(FE_ALL_EXCEPT);
	assert(envp);
	fesetenv(envp);
	feraiseexcept(ex);
	return 0;
}
