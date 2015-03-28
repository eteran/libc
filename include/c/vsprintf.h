
#ifndef VSPRINTF_20051228_H_
#define VSPRINTF_20051228_H_

#include "arch_va_list.h"

#ifdef __cplusplus
extern "C" {
#endif

int vsprintf(char *__ELIBC_RESTRICT str, const char *__ELIBC_RESTRICT format, va_list ap) __ELIBC_NOTHROW __attribute__((__format__ (printf, 2, 0)));

#ifdef __cplusplus
}
#endif

#endif
