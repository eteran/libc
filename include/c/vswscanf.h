
#ifndef _C_VSWSCANF_H_20140316_
#define _C_VSWSCANF_H_20140316_

#include "_file.h"
#include "arch_wchar_t.h"
#include <stdarg.h>

_LIBC_BEGIN

int vswscanf(const wchar_t *_RESTRICT ws, const wchar_t *_RESTRICT format, va_list arg) _NOEXCEPT;

_LIBC_END

#endif
