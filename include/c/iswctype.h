
#ifndef ISWCTYPE_20140316_H_
#define ISWCTYPE_20140316_H_

#include "_wctype_t.h"

#ifdef __cplusplus
extern "C" {
#endif

__ELIBC_CONST int iswctype(wint_t wc, wctype_t desc) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
