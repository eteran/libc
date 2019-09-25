
#ifndef FPUTC_20051228_H_
#define FPUTC_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_fputc(int c, FILE *stream, int orientation) _NOEXCEPT;
int fputc(int c, FILE *stream) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
