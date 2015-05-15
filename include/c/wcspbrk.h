
#ifndef WCSPBRK_20051228_H_
#define WCSPBRK_20051228_H_

#include "arch_wchar_t.h"

#ifdef __cplusplus
__ELIBC_PURE const wchar_t *wcspbrk(const wchar_t *, const wchar_t *) __ELIBC_NOTHROW __asm__("wcspbrk");
__ELIBC_PURE       wchar_t *wcspbrk(      wchar_t *, const wchar_t *) __ELIBC_NOTHROW __asm__("wcspbrk");
#else
__ELIBC_PURE wchar_t *wcspbrk(const wchar_t *, const wchar_t *) __ELIBC_NOTHROW;
#endif

#endif
