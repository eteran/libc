
#ifndef _C_VSCANF_H_20051228_
#define _C_VSCANF_H_20051228_

#include "arch_va_list.h"

_LIBC_BEGIN

int vscanf(const char *format, va_list ap) _NOEXCEPT _NON_NULL(1);

_LIBC_END

#endif
