
#ifndef _C_FPUTWS_H_20140316_
#define _C_FPUTWS_H_20140316_

#include "arch_wchar_t.h"
#include "_file.h"

_LIBC_BEGIN

int fputws(const wchar_t *ws, FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
