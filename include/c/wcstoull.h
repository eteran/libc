
#ifndef _C_WCSTOULL_H_20140701_
#define _C_WCSTOULL_H_20140701_

#include "arch_wchar_t.h"

_LIBC_BEGIN

unsigned long long wcstoull(const wchar_t * nptr, wchar_t ** endptr,
							int base) _NOEXCEPT;

_LIBC_END

#endif
