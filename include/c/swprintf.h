
#ifndef SWPRINTF_20140316_H_
#define SWPRINTF_20140316_H_

#ifdef __cplusplus
extern "C" {
#endif

int swprintf(wchar_t *ws, size_t n, const wchar_t *format, ...) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
