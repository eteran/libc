
#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "c/_support.h"
#include "heap.hpp"
#include "syscall.hpp"

#define __intptr_t_defined
#define __off_t_defined
#define __pid_t_defined

#include <asm/unistd.h>
#include <linux/signal.h>
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
pid_t __elibc_sys_fork() {
	long ret = elibc::syscall(__NR_fork);
	if (ret < 0) {
		errno = (__elibc_errno_t)-ret;
		ret   = -1;
	}

	return (pid_t)ret;
	;
}

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

	/* TODO(eteran): I don't know how this is supposed to work yet */
	ret = elibc::syscall(__NR_rt_sigaction, sig, &new_action, &old_action, 0);

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
		curbrk = elibc::syscall(__NR_brk, 0);
	}

	unsigned long ret = elibc::syscall(__NR_brk, curbrk + increment);
	if (ret != static_cast<unsigned long>(-1)) {
		curbrk = ret;
	}

	return ret;
}

namespace {
//------------------------------------------------------------------------------
// Name: do_div64
//------------------------------------------------------------------------------
template <typename T>
void do_div64(const T &numerator, const T &denominator, T &quotient, T &remainder) {

	static const int bits = sizeof(T) * CHAR_BIT;

	if (denominator == 0) {
		abort();
	} else {
		T n      = numerator;
		T d      = denominator;
		T x      = 1;
		T answer = 0;

		while ((n >= d) && (((d >> (bits - 1)) & 1) == 0)) {
			x <<= 1;
			d <<= 1;
		}

		while (x != 0) {
			if (n >= d) {
				n -= d;
				answer |= x;
			}

			x >>= 1;
			d >>= 1;
		}

		quotient  = answer;
		remainder = n;
	}
}
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
extern "C" uint64_t __udivdi3(uint64_t numerator, uint64_t denominator) {
	uint64_t quotient;
	uint64_t remainder;

	do_div64(numerator, denominator, quotient, remainder);
	return quotient;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
extern "C" uint64_t __umoddi3(uint64_t numerator, uint64_t denominator) {
	uint64_t quotient;
	uint64_t remainder;

	do_div64(numerator, denominator, quotient, remainder);
	return remainder;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
extern "C" int64_t __divdi3(int64_t numerator, int64_t denominator) {
	int64_t quotient;
	int64_t remainder;

	do_div64(numerator, denominator, quotient, remainder);
	return quotient;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
extern "C" uint64_t __moddi3(int64_t numerator, int64_t denominator) {
	int64_t quotient;
	int64_t remainder;

	do_div64(numerator, denominator, quotient, remainder);
	return remainder;
}
