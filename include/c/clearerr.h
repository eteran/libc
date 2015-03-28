
#ifndef CLEARERR_20051228_H_
#define CLEARERR_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

void __elibc_clearerr(FILE *stream) __ELIBC_NOTHROW;
void clearerr(FILE *stream) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
