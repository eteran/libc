
#ifndef BCOPY_20051228_H_
#define BCOPY_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
extern "C" {
#endif

_DEPRECATED void bcopy(const void *src, void *dest, size_t n) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
