
#ifndef CLEARERR_20051228_H_
#define CLEARERR_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

void __elibc_clearerr(FILE *stream) _NOEXCEPT;
void clearerr(FILE *stream) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
