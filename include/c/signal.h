
#ifndef SIGNAL_20140322_H_
#define SIGNAL_20140322_H_

#include "_sighandler_t.h"

_LIBC_BEGIN

__sighandler_t signal(int signum, __sighandler_t handler) _NOEXCEPT;

_LIBC_END

#endif
