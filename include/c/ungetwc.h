
#ifndef UNGETWC_20140316_H_
#define UNGETWC_20140316_H_

#include "_wint_t.h"

#ifdef __cplusplus
extern "C" {
#endif

wint_t ungetwc(wint_t wc, FILE *stream) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
