
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <time.h>

/*------------------------------------------------------------------------------
// Name: time
//----------------------------------------------------------------------------*/
time_t time(time_t *tod) {
	return __elibc_time(tod);
}
