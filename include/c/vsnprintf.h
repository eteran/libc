
#ifndef _C_VSNPRINTF_H_20051228_
#define _C_VSNPRINTF_H_20051228_

#include "arch_size_t.h"
#include "arch_va_list.h"

_LIBC_BEGIN

int vsnprintf(char * str, size_t size, const char * format, va_list ap) _NOEXCEPT;

_LIBC_END

#endif
