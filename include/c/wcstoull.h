
#ifndef WCSTOULL_20140701_H_
#define WCSTOULL_20140701_H_

#include "arch_wchar_t.h"

_LIBC_BEGIN

unsigned long long wcstoull(const wchar_t *_RESTRICT nptr, wchar_t **_RESTRICT endptr, int base) _NOEXCEPT;

_LIBC_END

#endif
