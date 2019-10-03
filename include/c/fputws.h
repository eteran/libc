
#ifndef FPUTWS_20140316_H_
#define FPUTWS_20140316_H_

#include "arch_wchar_t.h"
#include "_file.h"

_LIBC_BEGIN

int fputws(const wchar_t *ws, FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
