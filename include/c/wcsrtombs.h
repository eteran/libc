
#ifndef WCSRTOMBS_20140316_H_
#define WCSRTOMBS_20140316_H_

#ifdef __cplusplus
extern "C" {
#endif

size_t wcsrtombs(char *dest, const wchar_t **src, size_t len, mbstate_t *ps) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
