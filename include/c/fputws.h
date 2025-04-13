
#ifndef _C_FPUTWS_H_20140316_
#define _C_FPUTWS_H_20140316_

#include "_file.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

_ACCESS((read_only, 1))
_ACCESS((read_write, 2))
int fputws(const wchar_t *ws, FILE *stream) _NOEXCEPT _NON_NULL(1, 2);

_LIBC_END

#endif
