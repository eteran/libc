
#ifndef _C_SIGNAL_H_20140322_
#define _C_SIGNAL_H_20140322_

#include "_sighandler_t.h"

_LIBC_BEGIN

__sighandler_t signal(int signum, __sighandler_t handler) _NOEXCEPT;

_LIBC_END

#endif
