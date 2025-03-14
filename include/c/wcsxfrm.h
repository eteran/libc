
#ifndef _C_WCSXFRM_H_20140316_
#define _C_WCSXFRM_H_20140316_

#include "arch_size_t.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

size_t wcsxfrm(wchar_t * ws1, const wchar_t * ws2, size_t n) _NOEXCEPT;

_LIBC_END

#endif
