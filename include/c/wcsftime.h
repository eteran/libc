
#ifndef _C_WCSFTIME_H_20140316_
#define _C_WCSFTIME_H_20140316_

#include "_time.h"
#include "arch_size_t.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

size_t wcsftime(wchar_t *s, size_t max, const wchar_t *format, const struct tm *tm) _NOEXCEPT;

_LIBC_END

#endif
