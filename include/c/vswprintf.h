
#ifndef _C_VSWPRINTF_H_20140316_
#define _C_VSWPRINTF_H_20140316_

#include <stdarg.h>
#include "arch_wchar_t.h"
#include "arch_size_t.h"

_LIBC_BEGIN

int vswprintf(wchar_t *wcs, size_t n, const wchar_t *format, va_list ap) _NOEXCEPT;

_LIBC_END

#endif
