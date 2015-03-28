
#ifndef FPUTWC_20140316_H_
#define FPUTWC_20140316_H_

#include "_wint_t.h"

#ifdef __cplusplus
extern "C" {
#endif

wint_t __elibc_fputwc(wchar_t wc, FILE *stream, int orientation) __ELIBC_NOTHROW;
wint_t fputwc(wchar_t wc, FILE *stream) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
