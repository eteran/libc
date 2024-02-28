
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <signal.h>

/*------------------------------------------------------------------------------
// Name: raise
//----------------------------------------------------------------------------*/
int raise(int sig) {
	/* TODO(eteran): replace 0 with getpid? */
	return __elibc_sys_kill(0, sig);
}
