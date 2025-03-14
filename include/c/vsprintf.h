
#ifndef _C_VSPRINTF_H_20051228_
#define _C_VSPRINTF_H_20051228_

#include "arch_va_list.h"

_LIBC_BEGIN

int vsprintf(char * str, const char * format, va_list ap) _NOEXCEPT;

_LIBC_END

#endif
