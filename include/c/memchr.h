
#ifndef MEMCHR_20051228_H_
#define MEMCHR_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
_PURE const void *memchr(const void *s, int c, size_t n) _NOEXCEPT __asm__("memchr");
_PURE       void *memchr(      void *s, int c, size_t n) _NOEXCEPT __asm__("memchr");
#else
_PURE void *memchr(const void *s, int c, size_t n) _NOEXCEPT;
#endif

#endif
