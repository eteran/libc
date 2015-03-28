
#ifndef WCSTOK_20140316_H_
#define WCSTOK_20140316_H_

#ifdef __cplusplus
extern "C" {
#endif

wchar_t *wcstok(wchar_t *__ELIBC_RESTRICT s, const wchar_t *__ELIBC_RESTRICT delim) __ELIBC_NOTHROW;
wchar_t *wcstok_r(wchar_t *__ELIBC_RESTRICT s, const wchar_t *__ELIBC_RESTRICT delim, wchar_t **ptrptr) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
