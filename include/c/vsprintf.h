
#ifndef _C_VSPRINTF_H_20051228_
#define _C_VSPRINTF_H_20051228_

#include "arch_va_list.h"

_LIBC_BEGIN

int vsprintf(char *_RESTRICT str, const char *_RESTRICT format, va_list ap) _NOEXCEPT __attribute__((__format__ (printf, 2, 0)));

_LIBC_END

#endif
