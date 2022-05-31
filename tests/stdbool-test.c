/* 100% Coverage */

#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdbool.h>

int main(void) {
#ifndef __bool_true_false_are_defined
#error "__bool_true_false_are_defined is not defined"
#endif

#ifndef bool
#error "bool is not defined"
#endif

#ifndef true
#error "true is not defined"
#endif

#ifndef false
#error "false is not defined"
#endif

#if defined(__cplusplus) || defined(_HAS_C99)
	assert(true);
	assert(!false);
#endif
	return 0;
}
