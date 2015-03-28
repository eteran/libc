
#ifndef FPUTC_20051228_H_
#define FPUTC_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_fputc(int c, FILE *stream, int orientation) __ELIBC_NOTHROW;
int fputc(int c, FILE *stream) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
