
#ifndef _C_FPUTWC_H_20140316_
#define _C_FPUTWC_H_20140316_

#include "_file.h"
#include "_wint_t.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

wint_t __elibc_fputwc(wchar_t wc, FILE *stream, int orientation) _NOEXCEPT;
wint_t fputwc(wchar_t wc, FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
