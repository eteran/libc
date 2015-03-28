
#ifndef SPRINTF_20051228_H_
#define SPRINTF_20051228_H_

#ifdef __cplusplus
extern "C" {
#endif

int sprintf(char *__ELIBC_RESTRICT str, const char *__ELIBC_RESTRICT format, ...) __ELIBC_NOTHROW __attribute__((__format__ (printf, 2, 3)));

#ifdef __cplusplus
}
#endif

#endif
