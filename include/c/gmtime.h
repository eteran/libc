
#ifndef _C_GMTIME_H_20081228_
#define _C_GMTIME_H_20081228_

#include "_time.h"

_LIBC_BEGIN

struct tm *gmtime_r(const time_t *timep, struct tm *result) _NOEXCEPT;
struct tm *gmtime(const time_t *timep) _NOEXCEPT;

_LIBC_END

#endif
