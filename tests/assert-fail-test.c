/* 100% Coverage */

#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>

int main(void) {
	assert(2 + 2 == 5);
	return 0;
}
