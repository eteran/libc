
#ifndef STRTOK_20051228_H_
#define STRTOK_20051228_H_

_LIBC_BEGIN

char *strtok(char *_RESTRICT s, const char *_RESTRICT delim) _NOEXCEPT;
char *strtok_r(char *_RESTRICT s, const char *_RESTRICT delim, char **ptrptr) _NOEXCEPT;

_LIBC_END

#endif
