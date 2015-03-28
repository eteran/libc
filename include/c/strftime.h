
#ifndef STRFTIME_20051228_H_
#define STRFTIME_20051228_H_

#include "arch_size_t.h"
#include "_time.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t strftime(char *s, size_t max, const char *format, const struct tm *tm) __ELIBC_NOTHROW __attribute__ ((format (__strftime__, 3, 0)));

#ifdef __cplusplus
}
#endif

#endif
