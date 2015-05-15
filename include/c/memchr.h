
#ifndef MEMCHR_20051228_H_
#define MEMCHR_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
__ELIBC_PURE const void *memchr(const void *s, int c, size_t n) __ELIBC_NOTHROW __asm__("memchr");
__ELIBC_PURE       void *memchr(      void *s, int c, size_t n) __ELIBC_NOTHROW __asm__("memchr");
#else
__ELIBC_PURE void *memchr(const void *s, int c, size_t n) __ELIBC_NOTHROW;
#endif

#endif
