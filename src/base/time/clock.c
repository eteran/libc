
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <stdio.h>
#include <time.h>

/*------------------------------------------------------------------------------
// Name: clock
//----------------------------------------------------------------------------*/
clock_t clock(void) {
	return __elibc_clock();
}
