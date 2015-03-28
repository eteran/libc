
#ifndef FSEEK_20051228_H_
#define FSEEK_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_fseek(FILE *stream, long offset, int whence) __ELIBC_NOTHROW;
int fseek(FILE *stream, long offset, int whence) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
