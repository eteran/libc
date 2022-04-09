
#ifndef _C_VSNPRINTF_H_20051228_
#define _C_VSNPRINTF_H_20051228_

#include "arch_size_t.h"
#include "arch_va_list.h"

_LIBC_BEGIN

int vsnprintf(char *_RESTRICT str, size_t size, const char *_RESTRICT format, va_list ap) _NOEXCEPT
	__attribute__((__format__(printf, 3, 0)));

_LIBC_END

#endif
