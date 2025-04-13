
#ifndef _C_WMEMCPY_H_20140316_
#define _C_WMEMCPY_H_20140316_

#include "arch_size_t.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

wchar_t *wmemcpy(wchar_t *, const wchar_t *, size_t)
_NOEXCEPT _NON_NULL(1, 2);

_LIBC_END

#endif
