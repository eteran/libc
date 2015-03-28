
#ifndef WCSSTR_20051228_H_
#define WCSSTR_20051228_H_

#include "arch_wchar_t.h"

#ifdef __cplusplus
const wchar_t *wcsstr(const wchar_t *, const wchar_t *) __ELIBC_NOTHROW __asm__("wcsstr");
      wchar_t *wcsstr(      wchar_t *, const wchar_t *) __ELIBC_NOTHROW __asm__("wcsstr");
#else
wchar_t *wcsstr(const wchar_t *, const wchar_t *)__ELIBC_NOTHROW;
#endif

#endif





