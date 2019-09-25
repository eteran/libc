
#ifndef VWPRINTF_20140316_H_
#define VWPRINTF_20140316_H_

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

int vwprintf(const wchar_t *, va_list) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
