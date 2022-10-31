
#define _ELIBC_SOURCE
#include "signal.h"
#include "c/_support.h"

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
__sighandler_t signal(int signum, __sighandler_t handler) {
#ifdef __KERNEL__
	_UNUSED(signum);
	_UNUSED(handler);
	return SIG_ERR;
#else
	return (__sighandler_t)__elibc_sys_signal(signum, handler);
#endif

	/* signal()  returns  the  previous value of the signal handler, or SIG_ERR on error.  In the
	 * event of an error, errno is set to indicate the cause. */
}
