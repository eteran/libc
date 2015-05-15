
#ifndef WMEMCHR_20051228_H_
#define WMEMCHR_20051228_H_

#include "arch_wchar_t.h"

#ifdef __cplusplus
__ELIBC_PURE const wchar_t *wmemchr(const wchar_t *, wchar_t, size_t) __ELIBC_NOTHROW __asm__("wmemchr");
__ELIBC_PURE       wchar_t *wmemchr(      wchar_t *, wchar_t, size_t) __ELIBC_NOTHROW __asm__("wmemchr");
#else
__ELIBC_PURE wchar_t *wmemchr(const wchar_t *, wchar_t, size_t) __ELIBC_NOTHROW;
#endif

#endif
