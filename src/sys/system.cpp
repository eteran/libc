
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

/**
 * @brief Waits for a process to change state.
 *
 * @param pid the process id of the process to wait for
 * @param status a pointer to an integer where the exit status will be stored
 * @param options options for the wait operation
 * @return the process id of the child process that changed state, or -1 on error
 */
pid_t __elibc_sys_waitpid(pid_t pid, int *status, int options) {
	long ret = elibc::syscall(__NR_wait4, pid, status, options, 0);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return (pid_t)ret;
}

/**
 * @brief Creates a new process by duplicating the calling process.
 *
 * @return the process id of the child process, or -1 on error
 */
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

/**
 * @brief Deletes a name and possibly the file it refers to.
 *
 * @param filename the name of the file to be deleted.
 * @return 0 on success, or -1 on error
 */
int __elibc_sys_unlink(const char *filename) {
	long ret = elibc::syscall(__NR_unlink, filename);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return (int)ret;
}

/**
 * @brief Sends a signal to a process or a process group.
 *
 * @param pid the process id of the process to send the signal to
 * @param sig the signal to send
 * @return 0 on success, or -1 on error
 */
int __elibc_sys_kill(int pid, int sig) {
	long ret = elibc::syscall(__NR_kill, pid, sig);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return (int)ret;
}

/**
 * @brief Sets the disposition of a signal.
 *
 * @param sig the signal number
 * @param handler the new signal handler
 * @return the previous signal handler on success, or SIG_ERR on error
 */
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

/**
 * @brief Sets the position indicator of the open file description associated with the file descriptor.
 *
 * @param fildes the file descriptor
 * @param offset the offset to set
 * @param whence the reference point for the offset
 * @return the resulting offset location as measured in bytes from the beginning of the file, or -1 on error
 */
off_t __elibc_sys_lseek(int fildes, off_t offset, int whence) {
	long ret = elibc::syscall(__NR_lseek, fildes, offset, whence);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return ret;
}

/**
 * @brief Writes data to a file descriptor.
 *
 * @param fd the file descriptor
 * @param buf a pointer to the buffer containing the data to write
 * @param count the number of bytes to write
 * @return the number of bytes written, or -1 on error
 */
ssize_t __elibc_sys_write(int fd, const void *buf, size_t count) {
	long ret = elibc::syscall(__NR_write, fd, buf, count);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return (int)ret;
}

/**
 * @brief Reads data from a file descriptor.
 *
 * @param fd the file descriptor
 * @param buf a pointer to the buffer where the read data will be stored
 * @param count the number of bytes to read
 * @return the number of bytes read, or -1 on error
 */
ssize_t __elibc_sys_read(int fd, void *buf, size_t count) {
	long ret = elibc::syscall(__NR_read, fd, buf, count);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return (int)ret;
}

/**
 * @brief Closes a file descriptor.
 *
 * @param fd the file descriptor to close
 * @return 0 on success, or -1 on error
 */
int __elibc_sys_close(int fd) {
	long ret = elibc::syscall(__NR_close, fd);

	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return (int)ret;
}

/**
 * @brief Creates a new file or opens an existing file.
 *
 * @param pathname the name of the file to open
 * @param flags the file access mode
 * @return the file descriptor on success, or -1 on error
 */
int __elibc_sys_open(const char *pathname, int flags) {
	long ret = elibc::syscall(__NR_open, pathname, flags);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return (int)ret;
}

/**
 * @brief Retrieves the current time.
 *
 * @param tv a pointer to a timeval structure where the current time will be stored
 * @param tz a pointer to a timezone structure where the timezone information will be stored
 * @return 0 on success, or -1 on error
 */
int __elibc_sys_gettimeofday(struct timeval *tv, struct timezone *tz) {
	long ret = elibc::syscall(__NR_gettimeofday, tv, tz);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return (int)ret;
}

/**
 * @brief Terminate the calling process
 *
 * @param status the exit status of the process
 */
void __elibc_sys_exit(int status) {
	elibc::syscall(__NR_exit, status);
}

/**
 * @brief Frees memory previously allocated by a call to __elibc_malloc.
 *
 * @param ptr a pointer to the memory to free
 */
void __elibc_free(void *ptr) {
	heap::deallocate(ptr);
}

/**
 * @brief Allocates memory of the specified size.
 *
 * @param size the size of the memory block to allocate
 * @return a pointer to the allocated memory, or NULL on error
 */
void *__elibc_malloc(size_t size) {
	return heap::allocate(size);
}

/**
 * @brief Returns the size of the allocated memory block.
 *
 * @param ptr a pointer to the memory block
 * @return the size of the allocated memory block
 */
size_t __elibc_size(void *ptr) {
	return heap::block_size(ptr);
}

/**
 * @brief Initializes the heap.
 *
 */
void __elibc_init_heap(void) {
	heap::init();
}

/**
 * @brief Adjusts the program break by the specified amount.
 *
 * @param increment the amount to adjust the program break
 * @return the new program break on success, or (unsigned long)-1 on error
 */
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

/**
 * @brief Creates a child process and executes a shell command in it.
 *
 * @param command the shell command to execute
 * @return the exit status of the command, or -1 on error
 */
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

/**
 * @brief Returns the processor time used by the program.
 *
 * @return the processor time used by the program, or (clock_t)-1 on error
 */
clock_t __elibc_clock(void) {

	/* TODO(eteran): this is incorrect, because it is wall time, not time used
	 * by the process which is a big difference getrusage(RUSAGE_SELF, &ru)
	 * would be more appropriate
	 */

	struct timeval tv;
	memset(&tv, 0, sizeof(struct timeval));
	if (__elibc_sys_gettimeofday(&tv, 0) == -1) {
		return (clock_t)-1;
	}

	/* this assumes that CLOCKS_PER_SEC == 1000000,
	 * which it is according to POSIX
	 */
	return (clock_t)((tv.tv_sec * CLOCKS_PER_SEC) + tv.tv_usec);
}

/**
 * @brief Returns the current time.
 *
 * @param tod a pointer to a time_t object where the current time will be stored
 * @return the current time, or (time_t)-1 on error
 */
time_t __elibc_time(time_t *tod) {
	struct timeval tv;
	memset(&tv, 0, sizeof(struct timeval));

	if (__elibc_sys_gettimeofday(&tv, 0) == -1) {
		return (time_t)-1;
	}

	if (tod) {
		*tod = tv.tv_sec;
	}

	return tv.tv_sec;
}
