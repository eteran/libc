
#ifndef DIFFTIME_20051228_H_
#define DIFFTIME_20051228_H_

#include "_time.h"

#ifdef __cplusplus
extern "C" {
#endif

_CONST double difftime(time_t time1, time_t time0) _NOEXCEPT;

/* TODO(eteran): does the standard say this is a macro? */
#define difftime difftime

#ifdef __cplusplus
}
#endif

#endif
