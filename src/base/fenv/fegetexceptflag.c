
#define _ELIBC_SOURCE
#include <assert.h>
#include <fenv.h>

/**
 * @brief Retrieves the current floating-point exception flags and stores them in the specified object.
 *
 * @param fp A pointer to the object where the exception flags will be stored.
 * @param mask The mask specifying which exception flags to retrieve.
 * @note The mask can be a combination of the following values:
 * FE_INVALID, FE_DENORMAL, FE_DIVBYZERO, FE_OVERFLOW, FE_UNDERFLOW, FE_INEXACT.
 * @return int Returns 0 on success, or a non-zero value if an error occurs.
 */
int fegetexceptflag(fexcept_t *fp, int mask) {
	assert(fp);
	*fp = fetestexcept(mask);
	return 0;
}
