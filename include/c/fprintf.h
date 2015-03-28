
#ifndef FPRINTF_20051228_H_
#define FPRINTF_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int fprintf(FILE *__ELIBC_RESTRICT stream, const char *__ELIBC_RESTRICT format, ...) __ELIBC_NOTHROW __attribute__((__format__ (printf, 2, 3)));

#ifdef __cplusplus
}
#endif

#endif
