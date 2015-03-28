
#ifndef MBTOWC_20051228_H_
#define MBTOWC_20051228_H_

#include "arch_size_t.h"
#include "arch_wchar_t.h"

#ifdef __cplusplus
extern "C" {
#endif

int mbtowc(wchar_t * __ELIBC_RESTRICT pwc, const char *__ELIBC_RESTRICT s, size_t n) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
