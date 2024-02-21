
#ifndef _C_SUPPORT_H_20051228_
#define _C_SUPPORT_H_20051228_

#include "_sighandler_t.h"
#include "_time.h"
#include "arch_off_t.h"
#include "arch_pid_t.h"
#include "arch_size_t.h"

struct timeval;
struct timezone;

#ifdef __cplusplus
extern "C" {
#endif

/* basic system calls we need */
int __elibc_sys_close(int fd);
int __elibc_sys_gettimeofday(struct timeval *tv, struct timezone *tz);
int __elibc_sys_kill(int pid, int sig);
int __elibc_sys_open(const char *pathname, int flags);
int __elibc_sys_unlink(const char *filename);
long __elibc_sys_signal(int sig, __sighandler_t handler);
off_t __elibc_sys_lseek(int fildes, off_t offset, int whence);
ssize_t __elibc_sys_read(int fd, void *buf, size_t count);
ssize_t __elibc_sys_write(int fd, const void *buf, size_t count);
unsigned long __elibc_brk(unsigned long increment);
void __elibc_sys_exit(int status);

/* some system functions which depend very closely on system calls */
int __elibc_system(const char *command);
time_t __elibc_time(time_t *tod);
clock_t __elibc_clock(void);

/* allocation interface */
void __elibc_init_heap(void);
void __elibc_free(void *ptr);
void *__elibc_malloc(size_t size);
size_t __elibc_size(void *ptr);

/* globals */
extern char **__elibc_environment;

#ifdef __cplusplus
}
#endif

#endif
