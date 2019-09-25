
#ifndef FSEEK_20051228_H_
#define FSEEK_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_fseek(FILE *stream, long offset, int whence) _NOEXCEPT;
int fseek(FILE *stream, long offset, int whence) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
