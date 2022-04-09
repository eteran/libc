
#ifndef _C_VPRINTF_H_20051228_
#define _C_VPRINTF_H_20051228_

#include "arch_va_list.h"

_LIBC_BEGIN

int vprintf(const char *_RESTRICT format, va_list ap) _NOEXCEPT
	__attribute__((__format__(printf, 1, 0)));

_LIBC_END

#endif
