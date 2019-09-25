
#ifndef WCSTOK_20140316_H_
#define WCSTOK_20140316_H_

#ifdef __cplusplus
extern "C" {
#endif

wchar_t *wcstok(wchar_t *_RESTRICT s, const wchar_t *_RESTRICT delim) _NOEXCEPT;
wchar_t *wcstok_r(wchar_t *_RESTRICT s, const wchar_t *_RESTRICT delim, wchar_t **ptrptr) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
