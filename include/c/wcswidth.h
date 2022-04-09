
#ifndef _C_WCSWIDTH_H_20140316_
#define _C_WCSWIDTH_H_20140316_

#include "arch_size_t.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

_PURE int wcswidth(const wchar_t *wcs, size_t n) _NOEXCEPT;

_LIBC_END

#endif
