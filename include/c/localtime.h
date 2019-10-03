
#ifndef LOCALTIME_20051228_H_
#define LOCALTIME_20051228_H_

#include "arch_size_t.h"
#include "_time.h"

_LIBC_BEGIN

struct tm *localtime(const time_t *timer) _NOEXCEPT;
struct tm *localtime_r(const time_t *timep, struct tm *result) _NOEXCEPT;

_LIBC_END

#endif
