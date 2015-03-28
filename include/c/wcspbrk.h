
#ifndef WCSPBRK_20051228_H_
#define WCSPBRK_20051228_H_

#include "arch_wchar_t.h"

#ifdef __cplusplus
const wchar_t *wcspbrk(const wchar_t *, const wchar_t *) __ELIBC_NOTHROW __asm__("wcspbrk");
      wchar_t *wcspbrk(      wchar_t *, const wchar_t *) __ELIBC_NOTHROW __asm__("wcspbrk");
#else
wchar_t *wcspbrk(const wchar_t *, const wchar_t *) __ELIBC_NOTHROW;
#endif

#endif
