
#ifndef _C_LOCALTIME_H_20051228_
#define _C_LOCALTIME_H_20051228_

#include "_time.h"
#include "arch_size_t.h"

_LIBC_BEGIN

struct tm *localtime(const time_t *timer) _NOEXCEPT;
struct tm *localtime_r(const time_t *timep, struct tm *result) _NOEXCEPT;

_LIBC_END

#endif
