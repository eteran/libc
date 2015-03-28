
#ifndef FFLUSH_20051228_H_
#define FFLUSH_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_fflush(FILE *stream) __ELIBC_NOTHROW;
int fflush(FILE *stream) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
