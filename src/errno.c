
#define __ELIBC_SOURCE
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: __errno_location
//----------------------------------------------------------------------------*/
__elibc_errno_t *__errno_location(void) {
	_Thread_local static __elibc_errno_t __internal_errno = 0;
	return &__internal_errno;
}
