
#ifndef FPUTWC_20140316_H_
#define FPUTWC_20140316_H_

#include "_wint_t.h"

#ifdef __cplusplus
extern "C" {
#endif

wint_t __elibc_fputwc(wchar_t wc, FILE *stream, int orientation) _NOEXCEPT;
wint_t fputwc(wchar_t wc, FILE *stream) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
