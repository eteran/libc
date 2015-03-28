
#ifndef FGETC_20051228_H_
#define FGETC_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_fgetc(FILE *stream) __ELIBC_NOTHROW;
int fgetc(FILE *stream) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
