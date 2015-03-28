
#ifndef REWIND_20051228_H_
#define REWIND_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

void __elibc_rewind(FILE *stream) __ELIBC_NOTHROW;
void rewind(FILE *stream) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
