
#ifndef FGETS_20051228_H_
#define FGETS_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

char *__elibc_fgets(char *__ELIBC_RESTRICT s, int size, FILE *__ELIBC_RESTRICT stream) __ELIBC_NOTHROW;
char *fgets(char *__ELIBC_RESTRICT s, int size, FILE *__ELIBC_RESTRICT stream) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
