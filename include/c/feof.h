
#ifndef FEOF_20051228_H_
#define FEOF_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_feof(FILE *stream) __ELIBC_NOTHROW;
int feof(FILE *stream) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif


