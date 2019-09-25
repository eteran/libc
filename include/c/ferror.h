
#ifndef FERROR_20051228_H_
#define FERROR_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_ferror(FILE *stream) _NOEXCEPT;
int ferror(FILE *stream) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif


