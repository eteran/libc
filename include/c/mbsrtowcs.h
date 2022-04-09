
#ifndef _C_MBSRTOWCS_H_20140316_
#define _C_MBSRTOWCS_H_20140316_

#include "arch_size_t.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

size_t mbsrtowcs(wchar_t *dest, const char **src, size_t len, mbstate_t *ps) _NOEXCEPT;

_LIBC_END

#endif
