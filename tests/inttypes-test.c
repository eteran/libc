#undef NDEBUG
#define _ELIBC_SOURCE
#include "test_util.h"
#include <assert.h>
#include <inttypes.h>

void test_maxabs(void) {
	uintmax_t i = UINTMAX_MAX;
	assert(i == UINTMAX_MAX);

	assert(imaxabs(-100) == 100);
	assert(imaxabs(100) == 100);
}

int main(void) {

	TYPE_DEFINED(uintmax_t)
	test_maxabs();
	return 0;
}
