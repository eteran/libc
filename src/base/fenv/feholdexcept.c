
#define _ELIBC_SOURCE
#include <assert.h>
#include <fenv.h>

/**
 * @brief Saves the current floating point environment and clears all floating point exception flags.
 *
 * @param envp A pointer to the object where the floating point environment will be stored.
 * @return Returns 0 on success, or a non-zero value if an error occurs.
 */
int feholdexcept(fenv_t *envp) {
	assert(envp);
	fegetenv(envp);
	feclearexcept(FE_ALL_EXCEPT);
	return 0;
}
