
#ifndef WCSFTIME_20140316_H_
#define WCSFTIME_20140316_H_

#include "_time.h"
#include "arch_wchar_t.h"
#include "arch_size_t.h"

_LIBC_BEGIN

size_t wcsftime(wchar_t *s, size_t max, const wchar_t *format, const struct tm *tm) _NOEXCEPT;

_LIBC_END

#endif
