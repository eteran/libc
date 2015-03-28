
#ifndef STRTOK_20051228_H_
#define STRTOK_20051228_H_

#ifdef __cplusplus
extern "C" {
#endif

char *strtok(char *__ELIBC_RESTRICT s, const char *__ELIBC_RESTRICT delim) __ELIBC_NOTHROW;
char *strtok_r(char *__ELIBC_RESTRICT s, const char *__ELIBC_RESTRICT delim, char **ptrptr) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
