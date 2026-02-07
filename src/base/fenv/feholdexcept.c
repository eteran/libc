
#define _ELIBC_SOURCE
#include <assert.h>
#include <fenv.h>
#include <stdint.h>

/**
 * @brief Saves the current floating point environment and clears all floating point exception flags.
 *
 * @param envp A pointer to the object where the floating point environment will be stored.
 * @return Returns 0 on success, or a non-zero value if an error occurs.
 */
int feholdexcept(fenv_t *envp) {
	fenv_t env;
	assert(envp);
	fegetenv(envp);

	env = *envp;
	/* Mask all exceptions and clear pending flags in the active environment. */
	env.__control_word |= (unsigned short)FE_ALL_EXCEPT;
	env.__status_word &= (unsigned short)(~FE_ALL_EXCEPT);
	env.__mxcsr |= (uint32_t)(FE_ALL_EXCEPT << 7);
	env.__mxcsr &= (uint32_t)(~FE_ALL_EXCEPT);
	fesetenv(&env);
	feclearexcept(FE_ALL_EXCEPT);
	return 0;
}
