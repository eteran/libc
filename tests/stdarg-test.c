/* 100% Coverage */

#undef NDEBUG
#define _ELIBC_SOURCE
#include "test_util.h"
#include <assert.h>
#include <stdarg.h>
#include <string.h>

static void test_stdarg(int n, ...) {
	va_list ap;
	va_start(ap, n);
	assert(n == 5);
	assert(va_arg(ap, int) == 1);
	assert(strcmp("hello", va_arg(ap, const char *)) == 0);
	assert(va_arg(ap, int) == 'w');
	assert(va_arg(ap, int) == 4);
	assert(va_arg(ap, int) == 5);
	va_end(ap);
}

int main(void) {

#ifndef va_start
#error "va_start is not defined"
#endif

#ifndef va_arg
#error "va_arg is not defined"
#endif

#ifndef va_end
#error "va_end is not defined"
#endif

#ifdef _HAS_C99
#ifndef va_copy
#error "va_copy is not defined"
#endif
#endif

	TYPE_DEFINED(va_list);
	test_stdarg(5, 1, "hello", 'w', 4, 5);
	return 0;
}
