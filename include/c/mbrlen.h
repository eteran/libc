
#ifndef MBRLEN_20140316_H_
#define MBRLEN_20140316_H_

#include "arch_size_t.h"
#include "_mbstate_t.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t mbrlen(const char *_RESTRICT s, size_t n, mbstate_t *_RESTRICT ps) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
