
#ifndef _C_STRTOK_H_20051228_
#define _C_STRTOK_H_20051228_

_LIBC_BEGIN

char *strtok(char *_RESTRICT s, const char *_RESTRICT delim) _NOEXCEPT;
char *strtok_r(char *_RESTRICT s, const char *_RESTRICT delim, char **ptrptr) _NOEXCEPT;

_LIBC_END

#endif
