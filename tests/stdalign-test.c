/* 100% Coverage */

#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdalign.h>

int main(void) {
#ifndef __alignas_is_defined
#error "__alignas_is_defined is not defined"
#endif

#ifndef __alignof_is_defined
#error "__alignof_is_defined is not defined"
#endif

#ifndef alignas
#error "alignas is not defined"
#endif

#ifndef alignof
#error "alignof is not defined"
#endif

	assert(__alignas_is_defined == 1);
	assert(__alignof_is_defined == 1);
	return 0;
}
