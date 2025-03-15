
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <stdio.h>
#include <time.h>

/**
 * @brief Get processor time used by the program
 *
 * @return processor time used by the program
 */
clock_t clock(void) {
	return __elibc_clock();
}
