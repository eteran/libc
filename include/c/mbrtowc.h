
#ifndef MBRTOWC_20140316_H_
#define MBRTOWC_20140316_H_

#ifdef __cplusplus
extern "C" {
#endif

size_t mbrtowc(wchar_t *__ELIBC_RESTRICT pwc, const char *__ELIBC_RESTRICT s, size_t n, mbstate_t *ps) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
