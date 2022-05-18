
#define _ELIBC_SOURCE
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: __errno_location
//----------------------------------------------------------------------------*/
__elibc_errno_t *__errno_location(void) {
	static _Thread_local __elibc_errno_t __internal_errno = 0;
	return &__internal_errno;
}
