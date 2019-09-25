
#ifndef WCSFTIME_20140316_H_
#define WCSFTIME_20140316_H_

#include "_time.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t wcsftime(wchar_t *s, size_t max, const wchar_t *format, const struct tm *tm) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
