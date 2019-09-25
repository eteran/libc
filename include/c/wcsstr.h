
#ifndef WCSSTR_20051228_H_
#define WCSSTR_20051228_H_

#include "arch_wchar_t.h"

#ifdef __cplusplus
_PURE const wchar_t *wcsstr(const wchar_t *, const wchar_t *) _NOEXCEPT __asm__("wcsstr");
_PURE       wchar_t *wcsstr(      wchar_t *, const wchar_t *) _NOEXCEPT __asm__("wcsstr");
#else
_PURE wchar_t *wcsstr(const wchar_t *, const wchar_t *)_NOEXCEPT;
#endif

#endif





