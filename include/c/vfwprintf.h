
#ifndef VFWPRINTF_20140316_H_
#define VFWPRINTF_20140316_H_

#include <stdarg.h>
#include "arch_wchar_t.h"
#include "_file.h"

_LIBC_BEGIN

int vfwprintf(FILE *stream, const wchar_t *format, va_list ap) _NOEXCEPT;

_LIBC_END

#endif
