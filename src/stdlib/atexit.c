
#define __ELIBC_SOURCE
#include <stdlib.h>

static _atexit_t    __elibc_f_list[ATEXIT_MAX];
static unsigned int __elibc_f_index = 0;

/*------------------------------------------------------------------------------
// Name: atexit
//----------------------------------------------------------------------------*/
int atexit(_atexit_t function) {

	if (__elibc_f_index < ATEXIT_MAX) {
		__elibc_f_list[__elibc_f_index++] = function;
		return 0;
	}

	return -1;
}

/*------------------------------------------------------------------------------
// Name: __elibc_doexit
//----------------------------------------------------------------------------*/
void __elibc_doexit(void) {
	/* execute them in reverse order */
	while (__elibc_f_index > 0) {
		/* even though it should never be null, we'll check anyway */
		const _atexit_t func = __elibc_f_list[--__elibc_f_index];
		if (func) {
			(*func)();
		}
	}
}
