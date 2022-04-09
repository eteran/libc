
#ifndef _C_VFPRINTF_H_20051228_
#define _C_VFPRINTF_H_20051228_

#include "_file.h"
#include "arch_va_list.h"

_LIBC_BEGIN

int vfprintf(FILE *_RESTRICT stream, const char *_RESTRICT format, va_list ap) _NOEXCEPT
	__attribute__((__format__(printf, 2, 0)));

_LIBC_END

#endif
