
#ifndef TOWCTRANS_20140316_H_
#define TOWCTRANS_20140316_H_

#include "_wctrans_t.h"
#include "_wint_t.h"

#ifdef __cplusplus
extern "C" {
#endif

__ELIBC_CONST wint_t towctrans(wint_t wc, wctrans_t desc) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
