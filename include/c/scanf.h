
#ifndef SCANF_20051228_H_
#define SCANF_20051228_H_

#ifdef __cplusplus
extern "C" {
#endif

int scanf(const char *_RESTRICT format, ...) _NOEXCEPT __attribute__ ((format (__scanf__, 1, 2)));

#ifdef __cplusplus
}
#endif

#endif
