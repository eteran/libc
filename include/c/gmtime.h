
#ifndef GMTIME_20081228_H_
#define GMTIME_20081228_H_

#include "_time.h"

#ifdef __cplusplus
extern "C" {
#endif

struct tm *gmtime_r(const time_t *timep, struct tm *result) _NOEXCEPT;
struct tm *gmtime(const time_t *timep) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
