#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <inttypes.h>

int main(void) {
	uintmax_t i = UINTMAX_MAX;
	assert(i == UINTMAX_MAX);

	assert(imaxabs(-100) == 100);
	assert(imaxabs(100) == 100);
	return 0;
}
