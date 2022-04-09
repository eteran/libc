
#ifndef _C_WCSRCHR_H_20051228_
#define _C_WCSRCHR_H_20051228_

#include "arch_wchar_t.h"

#ifdef __cplusplus
_PURE const wchar_t *wcsrchr(const wchar_t *, wchar_t) _NOEXCEPT __asm__("wcsrchr");
_PURE wchar_t *wcsrchr(wchar_t *, wchar_t) _NOEXCEPT __asm__("wcsrchr");
#else
_PURE wchar_t *wcsrchr(const wchar_t *, wchar_t) _NOEXCEPT;
#endif

#endif
