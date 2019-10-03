
#define __ELIBC_SOURCE
#include "c/_support.h"
#include "signal.h"

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
__sighandler_t signal(int signum, __sighandler_t handler) {
#ifdef __KERNEL__
	(void)signum;
	(void)handler;
	return SIG_ERR;
#else
	return (__sighandler_t)__elibc_sys_signal(signum, handler);
#endif
}
