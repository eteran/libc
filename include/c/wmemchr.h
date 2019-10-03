
#ifndef WMEMCHR_20051228_H_
#define WMEMCHR_20051228_H_

#include "arch_wchar_t.h"
#include "arch_size_t.h"

#ifdef __cplusplus
_PURE const wchar_t *wmemchr(const wchar_t *, wchar_t, size_t) _NOEXCEPT __asm__("wmemchr");
_PURE       wchar_t *wmemchr(      wchar_t *, wchar_t, size_t) _NOEXCEPT __asm__("wmemchr");
#else
_PURE wchar_t *wmemchr(const wchar_t *, wchar_t, size_t) _NOEXCEPT;
#endif

#endif
