
#ifndef WCSCHR_20051228_H_
#define WCSCHR_20051228_H_

#include "arch_wchar_t.h"

#ifdef __cplusplus
__ELIBC_PURE const wchar_t *wcschr(const wchar_t *s, wchar_t c) __ELIBC_NOTHROW __asm__("wcschr");
__ELIBC_PURE       wchar_t *wcschr(      wchar_t *s, wchar_t c) __ELIBC_NOTHROW __asm__("wcschr");
#else
__ELIBC_PURE wchar_t *wcschr(const wchar_t *s, wchar_t c) __ELIBC_NOTHROW;
#endif

#endif
