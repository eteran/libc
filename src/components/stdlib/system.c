
#define _ELIBC_SOURCE
#include <assert.h>
#include <errno.h>
#include <stdlib.h>

#if defined(__linux__) && !defined(__KERNEL__) && 0
#include <asm/unistd.h>
#include <sys/types.h>
_syscall0(pid_t, fork)
_syscall3(pid_t, waitpid, pid_t, pid, int *, status, int, options)
#endif

/*------------------------------------------------------------------------------
// Name: system
//----------------------------------------------------------------------------*/
int system(const char *command) {

	int ret = 0;
	if (command) {
#ifdef __KERNEL__
		/* in kernel mode this should do nothing...
		 * in fact, lets give a warning if used in kernel land..
		 * it is clearly a logic error
		 */
		assert(!command); /* die with an assert for now */
		return -1;
#elif defined(__linux__) && 0
		const int pid = fork();

		switch (pid) {
		case 0:
			/* we are in the child */
			execlp("sh", "sh", "-c", command, 0);
			exit(127);
			break;
		case -1:
			ret = -1;
			break;
		default:
			/* we are in the parent */
			waitpid(pid, &ret, 0);
		}
#endif
	}
	return ret;
}
