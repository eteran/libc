
#ifndef _C_WMEMCHR_H_20051228_
#define _C_WMEMCHR_H_20051228_

#include "arch_size_t.h"
#include "arch_wchar_t.h"

#ifdef __cplusplus
_PURE const wchar_t *wmemchr(const wchar_t *, wchar_t, size_t)
_NOEXCEPT __asm__("wmemchr");
_PURE wchar_t *wmemchr(wchar_t *, wchar_t, size_t)
_NOEXCEPT __asm__("wmemchr");
#else
_PURE wchar_t *wmemchr(const wchar_t *, wchar_t, size_t)
_NOEXCEPT _NON_NULL(1);
#endif

#endif
