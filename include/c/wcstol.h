
#ifndef _C_WCSTOL_H_20140316_
#define _C_WCSTOL_H_20140316_

#include "arch_wchar_t.h"

_LIBC_BEGIN

long int wcstol(const wchar_t *_RESTRICT nptr, wchar_t **_RESTRICT endptr, int base) _NOEXCEPT;

_LIBC_END

#endif
