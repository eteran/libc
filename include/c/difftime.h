
#ifndef _C_DIFFTIME_H_20051228_
#define _C_DIFFTIME_H_20051228_

#include "_time.h"

_LIBC_BEGIN

_CONST double difftime(time_t time1, time_t time0) _NOEXCEPT;

/* TODO(eteran): does the standard say this is a macro? */
#define difftime difftime

_LIBC_END

#endif
