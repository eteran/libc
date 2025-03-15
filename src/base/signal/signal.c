
#define _ELIBC_SOURCE
#include "signal.h"
#include "c/_support.h"

/**
 * @brief Set the signal handler for a given signal
 *
 * @param signum the signal number
 * @param handler the signal handler
 * @return the previous signal handler, or SIG_ERR on error
 */
__sighandler_t signal(int signum, __sighandler_t handler) {
	return (__sighandler_t)__elibc_sys_signal(signum, handler);
	/* signal()  returns  the  previous value of the signal handler, or SIG_ERR on error.  In the
	 * event of an error, errno is set to indicate the cause. */
}
