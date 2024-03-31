
#ifndef _C_VFWPRINTF_H_20140316_
#define _C_VFWPRINTF_H_20140316_

#include "_file.h"
#include "arch_wchar_t.h"
#include <stdarg.h>

_LIBC_BEGIN

int vfwprintf(FILE *stream, const wchar_t *format, va_list args) _NOEXCEPT;

_LIBC_END

#endif
