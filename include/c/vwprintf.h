
#ifndef _C_VWPRINTF_H_20140316_
#define _C_VWPRINTF_H_20140316_

#include "arch_wchar_t.h"
#include <stdarg.h>

_LIBC_BEGIN

int vwprintf(const wchar_t *, va_list) _NOEXCEPT;

_LIBC_END

#endif
