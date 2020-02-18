
#ifndef _C_SWPRINTF_H_20140316_
#define _C_SWPRINTF_H_20140316_

#include "arch_wchar_t.h"
#include "arch_size_t.h"

_LIBC_BEGIN

int swprintf(wchar_t *ws, size_t n, const wchar_t *format, ...) _NOEXCEPT;

_LIBC_END

#endif
