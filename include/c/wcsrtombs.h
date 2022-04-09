
#ifndef _C_WCSRTOMBS_H_20140316_
#define _C_WCSRTOMBS_H_20140316_

#include "arch_size_t.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

size_t wcsrtombs(char *dest, const wchar_t **src, size_t len, mbstate_t *ps) _NOEXCEPT;

_LIBC_END

#endif
