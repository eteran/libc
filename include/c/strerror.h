
#ifndef STRERROR_20051228_H_
#define STRERROR_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
extern "C" {
#endif

int strerror_r(int errnum, char *buf, size_t n) _NOEXCEPT;
char *strerror(int errnum) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
