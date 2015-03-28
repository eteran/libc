
#ifndef WCSRCHR_20051228_H_
#define WCSRCHR_20051228_H_

#include "arch_wchar_t.h"

#ifdef __cplusplus
const wchar_t *wcsrchr(const wchar_t *, wchar_t) __ELIBC_NOTHROW __asm__("wcsrchr");
      wchar_t *wcsrchr(      wchar_t *, wchar_t) __ELIBC_NOTHROW __asm__("wcsrchr");
#else
wchar_t *wcsrchr(const wchar_t *, wchar_t) __ELIBC_NOTHROW;
#endif

#endif



