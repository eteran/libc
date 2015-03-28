
#ifndef VSWPRINTF_20140316_H_
#define VSWPRINTF_20140316_H_

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

int vswprintf(wchar_t *wcs, size_t n, const wchar_t *format, va_list ap) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
