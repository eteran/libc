
#define _ELIBC_SOURCE
#include <assert.h>
#include <errno.h>
#include <stdlib.h>

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
		const pid_t pid = __elibc_sys_fork();

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
			__elibc_sys_waitpid(pid, &ret, 0);
		}
#endif
	}
	return ret;
}
