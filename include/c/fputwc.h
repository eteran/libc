
#ifndef FPUTWC_20140316_H_
#define FPUTWC_20140316_H_

#include "_wint_t.h"
#include "_file.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

wint_t __elibc_fputwc(wchar_t wc, FILE *stream, int orientation) _NOEXCEPT;
wint_t fputwc(wchar_t wc, FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
