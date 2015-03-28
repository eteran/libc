
#ifndef FPUTS_20051228_H_
#define FPUTS_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_fputs(const char *__ELIBC_RESTRICT s, FILE *__ELIBC_RESTRICT stream) __ELIBC_NOTHROW;
int fputs(const char *__ELIBC_RESTRICT s, FILE *__ELIBC_RESTRICT stream) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
