
#ifndef SETVBUF_20051228_H_
#define SETVBUF_20051228_H_

#include "_file.h"
#include "arch_size_t.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_setvbuf(FILE *__ELIBC_RESTRICT stream, char *__ELIBC_RESTRICT buf, int mode, size_t size) __ELIBC_NOTHROW;
int setvbuf(FILE *__ELIBC_RESTRICT stream, char *__ELIBC_RESTRICT buf, int mode , size_t size) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
