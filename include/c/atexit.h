
#ifndef _C_ATEXIT_H_20051228_
#define _C_ATEXIT_H_20051228_

#define ATEXIT_MAX 32

_LIBC_BEGIN

typedef void (*_atexit_t)(void);

int atexit(_atexit_t function) _NOEXCEPT;
void __elibc_doexit(void);

_LIBC_END

#endif
