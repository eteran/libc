
#ifndef MBSTOWCS_20051228_H_
#define MBSTOWCS_20051228_H_

#ifdef __cplusplus
extern "C" {
#endif

size_t mbstowcs(wchar_t *pwcs, const char *s, size_t n) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
