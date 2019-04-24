
#define __ELIBC_SOURCE
#include <signal.h>
#include "c/_support.h"

/*------------------------------------------------------------------------------
// Name: raise
//----------------------------------------------------------------------------*/
int raise(int sig) {
#ifdef __KERNEL__
	(void)sig;
	return -1;
#else
	/* TODO(eteran): replace 0 with getpid? */
	return __elibc_sys_kill(0, sig);
#endif

}
