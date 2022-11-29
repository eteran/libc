
#ifndef _C_WCSTOULL_H_20140701_
#define _C_WCSTOULL_H_20140701_

#include "arch_wchar_t.h"

_LIBC_BEGIN

unsigned long long wcstoull(const wchar_t *_RESTRICT nptr, wchar_t **_RESTRICT endptr,
							int base) _NOEXCEPT;

_LIBC_END

#endif
