
#ifndef FFLUSH_20051228_H_
#define FFLUSH_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_fflush(FILE *stream) _NOEXCEPT;
int fflush(FILE *stream) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
