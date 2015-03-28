
#ifndef VPRINTF_20051228_H_
#define VPRINTF_20051228_H_

#include "arch_va_list.h"

#ifdef __cplusplus
extern "C" {
#endif

int vprintf(const char *__ELIBC_RESTRICT format, va_list ap) __ELIBC_NOTHROW __attribute__((__format__ (printf, 1, 0)));

#ifdef __cplusplus
}
#endif

#endif
