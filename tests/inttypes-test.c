#undef NDEBUG
#include <assert.h>
#ifdef _HAS_C99
#include <inttypes.h>
#endif

int main(void) {
#ifdef _HAS_C99
	uintmax_t i = UINTMAX_MAX;
	assert(i == UINTMAX_MAX);

	assert(imaxabs(-100) == 100);
	assert(imaxabs(100) == 100);

#endif
	return 0;
}
