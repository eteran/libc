
#ifndef _SUPPORT_20051228_H_
#define _SUPPORT_20051228_H_

#include "arch_size_t.h"
#include "arch_off_t.h"
#include "_time.h"
#include "_sighandler_t.h"
#include "_posix_time.h"

#ifdef __cplusplus
extern "C" {
#endif

/* basic system calls we need */
int           __elibc_sys_kill(int pid, int sig);
long          __elibc_sys_signal(int sig, __sighandler_t handler);
off_t         __elibc_sys_lseek(int fildes, off_t offset, int whence);
ssize_t       __elibc_sys_write(int fd, const void *buf, size_t count);
ssize_t       __elibc_sys_read(int fd, void *buf, size_t count);
int           __elibc_sys_close(int fd);
int           __elibc_sys_open(const char *pathname, int flags);
int           __elibc_sys_gettimeofday(struct timeval *tv, struct timezone *tz);
void          __elibc_sys_exit(int status);
unsigned long __elibc_brk(unsigned long increment);

/* allocation interface */
void   __elibc_init_heap(void);
void   __elibc_free(void *ptr);
void * __elibc_malloc(size_t size);
size_t __elibc_size(void *ptr);

#ifdef __cplusplus
}
#endif

#endif
