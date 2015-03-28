
#ifndef MBSRTOWCS_20140316_H_
#define MBSRTOWCS_20140316_H_

#ifdef __cplusplus
extern "C" {
#endif

size_t mbsrtowcs(wchar_t *dest, const char **src, size_t len, mbstate_t *ps) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
