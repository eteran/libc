
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <signal.h>

/**
 * @brief Raise a signal in the current process
 *
 * @param sig the signal to raise
 * @return 0 on success, or -1 on error
 */
int raise(int sig) {
	/* TODO(eteran): replace 0 with getpid? */
	return __elibc_sys_kill(0, sig);
}
