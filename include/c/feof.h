
#ifndef FEOF_20051228_H_
#define FEOF_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_feof(FILE *stream) _NOEXCEPT;
int feof(FILE *stream) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif


