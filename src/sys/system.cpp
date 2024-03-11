
#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "c/_support.h"
#include "heap.hpp"
#include "syscall.hpp"

#define __intptr_t_defined
#define __off_t_defined
#define __pid_t_defined

#include <asm/unistd.h>
#include <linux/signal.h>
#include <linux/time.h>
#include <sys/syscall.h>
#include <unistd.h>

#if 0
	environ
x	fork
	fstat
	getpid
	isatty
	link
	stat
x	unlink
x	wait
x	write
?	times
x	_exit
x	close
x	kill
x	lseek
x	open
x	read
x	sbrk
#endif
#if 0
namespace {

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
pid_t __elibc_sys_waitpid(pid_t pid, int *status, int options) {
	long ret = elibc::syscall(__NR_wait4, pid, status, options, 0);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return (pid_t)ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
pid_t __elibc_sys_fork(void) {
	long ret = elibc::syscall(__NR_fork);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return (pid_t)ret;
}

}
#endif

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
int __elibc_sys_unlink(const char *filename) {
	long ret = elibc::syscall(__NR_unlink, filename);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return 0;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
int __elibc_sys_kill(int pid, int sig) {
	long ret = elibc::syscall(__NR_kill, pid, sig);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return 0;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
long __elibc_sys_signal(int sig, __sighandler_t handler) {
	long ret = -1;

	sigaction old_action;
	sigaction new_action;

	memset(&old_action, 0, sizeof(sigaction));
	memset(&new_action, 0, sizeof(sigaction));
	new_action.sa_handler = handler;
	new_action.sa_mask    = 0;
	new_action.sa_flags   = SA_RESTART;

	/* TODO(eteran): I don't know how this is supposed to work yet */
	ret = elibc::syscall(__NR_rt_sigaction, sig, &new_action, &old_action, sizeof(sigset_t));

	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = (long)SIG_ERR;
	}
	return ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
off_t __elibc_sys_lseek(int fildes, off_t offset, int whence) {
	long ret = elibc::syscall(__NR_lseek, fildes, offset, whence);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
ssize_t __elibc_sys_write(int fd, const void *buf, size_t count) {
	long ret = elibc::syscall(__NR_write, fd, buf, count);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
ssize_t __elibc_sys_read(int fd, void *buf, size_t count) {
	long ret = elibc::syscall(__NR_read, fd, buf, count);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
int __elibc_sys_close(int fd) {
	long ret = elibc::syscall(__NR_close, fd);

	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return 0;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
int __elibc_sys_open(const char *pathname, int flags) {
	long ret = elibc::syscall(__NR_open, pathname, flags);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return (int)ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
int __elibc_sys_gettimeofday(struct timeval *tv, struct timezone *tz) {
	long ret = elibc::syscall(__NR_gettimeofday, tv, tz);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return (int)ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void __elibc_sys_exit(int status) {
	elibc::syscall(__NR_exit, status);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void __elibc_free(void *ptr) {
	heap::deallocate(ptr);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void *__elibc_malloc(size_t size) {
	return heap::allocate(size);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
size_t __elibc_size(void *ptr) {
	return heap::block_size(ptr);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
void __elibc_init_heap(void) {
	heap::init();
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
unsigned long __elibc_brk(unsigned long increment) {
	static unsigned long curbrk = 0;

	if (curbrk == 0) {
		curbrk = static_cast<unsigned long>(elibc::syscall(__NR_brk, 0));
	}

	auto ret = static_cast<unsigned long>(elibc::syscall(__NR_brk, curbrk + increment));
	if (ret != static_cast<unsigned long>(-1)) {
		curbrk = ret;
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
int __elibc_system(const char *command) {
	int ret = 0;
	if (command) {
#if 0
		const pid_t pid = __elibc_sys_fork();

		switch (pid) {
		case 0:
			/* we are in the child */
			execlp("sh", "sh", "-c", command, 0);
			__elibc_sys_exit(127);
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

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
clock_t __elibc_clock(void) {

	/* TODO(eteran): this is incorrect, because it is wall time, not time used
	 * by the process which is a big difference getrusage(RUSAGE_SELF, &ru)
	 * would be more appropriate
	 */

	struct timeval tv;
	if (__elibc_sys_gettimeofday(&tv, 0) == -1) {
		return (clock_t)-1;
	}

	/* this assumes that CLOCKS_PER_SEC == 1000000,
	 * which it is according to POSIX
	 */
	return (clock_t)((tv.tv_sec * CLOCKS_PER_SEC) + tv.tv_usec);
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
time_t __elibc_time(time_t *tod) {
	struct timeval tv;

	if (__elibc_sys_gettimeofday(&tv, 0) == 0) {
		if (tod) {
			*tod = tv.tv_sec;
		}

		return tv.tv_sec;
	}

	return (time_t)-1;
}
