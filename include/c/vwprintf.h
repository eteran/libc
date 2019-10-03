
#ifndef VWPRINTF_20140316_H_
#define VWPRINTF_20140316_H_

#include <stdarg.h>
#include "arch_wchar_t.h"

_LIBC_BEGIN

int vwprintf(const wchar_t *, va_list) _NOEXCEPT;

_LIBC_END

#endif
