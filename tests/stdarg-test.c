/* 100% Coverage */

#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdarg.h>
#include "test_util.h"

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

	TYPE_DEFNIED(va_list)

	return 0;
}
