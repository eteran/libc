
#ifndef SIGNAL_20140322_H_
#define SIGNAL_20140322_H_

#include "_sighandler_t.h"

#ifdef __cplusplus
extern "C" {
#endif

__sighandler_t signal(int signum, __sighandler_t handler) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
