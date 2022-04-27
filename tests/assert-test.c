/* 100% Coverage */

#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>

int main(void) {
	assert(2 + 2 == 4);
	return 0;
}
