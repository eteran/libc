
#ifndef MBRTOWC_20140316_H_
#define MBRTOWC_20140316_H_

#ifdef __cplusplus
extern "C" {
#endif

size_t mbrtowc(wchar_t *_RESTRICT pwc, const char *_RESTRICT s, size_t n, mbstate_t *ps) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
