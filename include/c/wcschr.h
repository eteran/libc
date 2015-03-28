
#ifndef WCSCHR_20051228_H_
#define WCSCHR_20051228_H_

#include "arch_wchar_t.h"

#ifdef __cplusplus
const wchar_t *wcschr(const wchar_t *s, wchar_t c) __ELIBC_NOTHROW __asm__("wcschr");
      wchar_t *wcschr(      wchar_t *s, wchar_t c) __ELIBC_NOTHROW __asm__("wcschr");
#else
wchar_t *wcschr(const wchar_t *s, wchar_t c) __ELIBC_NOTHROW;
#endif

#endif
