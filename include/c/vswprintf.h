
#ifndef VSWPRINTF_20140316_H_
#define VSWPRINTF_20140316_H_

#include <stdarg.h>
#include "arch_wchar_t.h"
#include "arch_size_t.h"

_LIBC_BEGIN

int vswprintf(wchar_t *wcs, size_t n, const wchar_t *format, va_list ap) _NOEXCEPT;

_LIBC_END

#endif
