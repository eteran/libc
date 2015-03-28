
#ifndef VFPRINTF_20051228_H_
#define VFPRINTF_20051228_H_

#include "arch_va_list.h"
#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int vfprintf(FILE *__ELIBC_RESTRICT stream, const char *__ELIBC_RESTRICT format, va_list ap) __ELIBC_NOTHROW __attribute__((__format__ (printf, 2, 0)));

#ifdef __cplusplus
}
#endif

#endif
