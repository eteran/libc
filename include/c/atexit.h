
#ifndef ATEXIT_20051228_H_
#define ATEXIT_20051228_H_

#define ATEXIT_MAX 32

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*_atexit_t)(void);

int atexit(_atexit_t function) _NOEXCEPT;
void __elibc_doexit(void);

#ifdef __cplusplus
}
#endif

#endif
