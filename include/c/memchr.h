
#ifndef _C_MEMCHR_H_20051228_
#define _C_MEMCHR_H_20051228_

#include "arch_size_t.h"

#ifdef __cplusplus
_PURE const void *memchr(const void *s, int c, size_t n) _NOEXCEPT __asm__("memchr");
_PURE void *memchr(void *s, int c, size_t n) _NOEXCEPT __asm__("memchr");
#else
_ACCESS((read_only, 1))
_PURE void *memchr(const void *s, int c, size_t n) _NOEXCEPT;
#endif

#endif
