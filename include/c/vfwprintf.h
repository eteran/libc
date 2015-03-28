
#ifndef VFWPRINTF_20140316_H_
#define VFWPRINTF_20140316_H_

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

int vfwprintf(FILE *stream, const wchar_t *format, va_list ap) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
