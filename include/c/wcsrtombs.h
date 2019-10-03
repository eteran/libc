
#ifndef WCSRTOMBS_20140316_H_
#define WCSRTOMBS_20140316_H_

#include "arch_wchar_t.h"
#include "arch_size_t.h"

_LIBC_BEGIN

size_t wcsrtombs(char *dest, const wchar_t **src, size_t len, mbstate_t *ps) _NOEXCEPT;

_LIBC_END

#endif
