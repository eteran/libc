
#ifndef MBRTOWC_20140316_H_
#define MBRTOWC_20140316_H_

#include "arch_wchar_t.h"
#include "arch_size_t.h"

_LIBC_BEGIN

size_t mbrtowc(wchar_t *_RESTRICT pwc, const char *_RESTRICT s, size_t n, mbstate_t *ps) _NOEXCEPT;

_LIBC_END

#endif
