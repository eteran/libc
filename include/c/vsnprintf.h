
#ifndef VSNPRINTF_20051228_H_
#define VSNPRINTF_20051228_H_

#include "arch_size_t.h"
#include "arch_va_list.h"

#ifdef __cplusplus
extern "C" {
#endif

int vsnprintf(char *__ELIBC_RESTRICT str, size_t size, const char *__ELIBC_RESTRICT format, va_list ap) __ELIBC_NOTHROW __attribute__((__format__ (printf, 3, 0)));

#ifdef __cplusplus
}
#endif

#endif
