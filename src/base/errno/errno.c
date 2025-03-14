
#define _ELIBC_SOURCE
#include <errno.h>

/**
 * @brief Returns a pointer to the thread-local errno variable.
 *
 * @return __elibc_errno_t* A pointer to the thread-local errno variable.
 */
__elibc_errno_t *__errno_location(void) {
	static _Thread_local __elibc_errno_t __internal_errno = 0;
	return &__internal_errno;
}
