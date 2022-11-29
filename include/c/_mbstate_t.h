
#ifndef _C_MBSTATE_T_H_20140319_
#define _C_MBSTATE_T_H_20140319_

#include "arch_wchar_t.h"

typedef struct {
	wchar_t wc;
	unsigned int expected : 4;
	unsigned int seen : 4;
} mbstate_t;

#endif
