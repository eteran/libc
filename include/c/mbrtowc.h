
#ifndef _C_MBRTOWC_H_20140316_
#define _C_MBRTOWC_H_20140316_

#include "arch_size_t.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

size_t mbrtowc(wchar_t * pwc, const char * s, size_t n, mbstate_t *ps) _NOEXCEPT;

_LIBC_END

#endif
