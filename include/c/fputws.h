
#ifndef _C_FPUTWS_H_20140316_
#define _C_FPUTWS_H_20140316_

#include "_file.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

int fputws(const wchar_t *ws, FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
