
#define _ELIBC_SOURCE
#include <assert.h>
#include <fenv.h>

/**
 * @brief Sets the floating point exception flags specified by the mask to the values stored in the given object.
 *
 * @param fp A pointer to the object containing the exception flags to set.
 * @param mask The mask specifying which exception flags to set.
 * @return Returns 0 on success, or a non-zero value if an error occurs.
 */
int fesetexceptflag(const fexcept_t *fp, int mask) {
	assert(fp);
	feclearexcept(~*fp & mask);
	feraiseexcept(*fp & mask);
	return 0;
}
