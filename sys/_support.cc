
#include <errno.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <signal.h>
#include <stdint.h>

#include "c/_support.h"
#include "heap.h"
#include "syscall.h"

#define __intptr_t_defined
#define __off_t_defined

#include <asm/unistd.h>
#include <unistd.h>
#include <sys/syscall.h>

#if 0
	environ
	fork
	fstat
	getpid
	isatty
	link
	stat
	unlink
	wait
#	write
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
int __elibc_sys_kill(int pid, int sig) {
	long ret = elibc::syscall(__NR_kill, pid, sig);
	if(ret < 0) {
		errno = -ret;
		ret = -1;
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
long __elibc_sys_signal(int sig, __sighandler_t handler) {
	long ret = -1;
	(void)sig;
	(void)handler;
#ifdef __NR_signal
	ret = elibc::syscall(__NR_signal, sig, handler);

	if(ret < 0) {
		errno = -ret;
		ret = (long)SIG_ERR;
	}
#endif
	return ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
off_t __elibc_sys_lseek(int fildes, off_t offset, int whence) {
	long ret = elibc::syscall(__NR_lseek, fildes, offset, whence);
	if(ret < 0) {
		errno = -ret;
		ret = -1;
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
ssize_t __elibc_sys_write(int fd, const void *buf, size_t count) {
	long ret = elibc::syscall(__NR_write, fd, buf, count);
	if(ret < 0) {
		errno = -ret;
		ret = -1;
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
ssize_t __elibc_sys_read(int fd, void *buf, size_t count) {
	long ret = elibc::syscall(__NR_read, fd, buf, count);
	if(ret < 0) {
		errno = -ret;
		ret = -1;
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
int __elibc_sys_close(int fd) {
	long ret = elibc::syscall(__NR_close, fd);

	if(ret < 0) {
		errno = -ret;
		ret = -1;
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
int __elibc_sys_open(const char *pathname, int flags) {
	long ret = elibc::syscall(__NR_open, pathname, flags);
	if(ret < 0) {
		errno = -ret;
		ret = -1;
	}

	return ret;
}

//------------------------------------------------------------------------------
// Name:
//------------------------------------------------------------------------------
int __elibc_sys_gettimeofday(struct timeval *tv, struct timezone *tz) {
	long ret = elibc::syscall(__NR_gettimeofday, tv, tz);
	if(ret < 0) {
		errno = -ret;
		ret = -1;
	}

	return ret;
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

	if(curbrk == 0) {
		curbrk = elibc::syscall(__NR_brk, 0);
	}

	unsigned long ret = elibc::syscall(__NR_brk, curbrk + increment);
	if(ret != static_cast<unsigned long>(-1)) {
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

	if(denominator == 0) {
		abort();
		quotient = 0;
		remainder = 0;
	} else {
		T n      = numerator;
		T d      = denominator;
		T x      = 1;
		T answer = 0;

		while((n >= d) && (((d >> (bits - 1)) & 1) == 0)) {
			x <<= 1;
			d <<= 1;
		}

		while(x != 0) {
			if(n >= d) {
				n -= d;
				answer |= x;
			}

			x >>= 1;
			d >>= 1;
		}

		quotient = answer;
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

