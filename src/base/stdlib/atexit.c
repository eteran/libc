
#define _ELIBC_SOURCE
#include <stdlib.h>

static _atexit_t __elibc_f_list[ATEXIT_MAX];
static unsigned int __elibc_f_index = 0;

/**
 * @brief Register a function to be called at program exit
 *
 * @param function a pointer to the function to register
 * @return int 0 on success, -1 on failure
 */
int atexit(_atexit_t function) {

	if (__elibc_f_index < ATEXIT_MAX) {
		__elibc_f_list[__elibc_f_index++] = function;
		return 0;
	}

	return -1;
}

/**
 * @brief Call all functions registered with atexit in reverse order
 *
 */
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
