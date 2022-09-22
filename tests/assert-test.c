/* 100% Coverage */

#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>

#ifdef _HAS_C11
#ifndef static_assert
#error "static_assert, not defined"
#endif
#endif

int main(void) {
	assert(2 + 2 == 4);

	return 0;
}
