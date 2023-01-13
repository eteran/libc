#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdatomic.h>

int main(void) {
#ifdef _HAS_C11
	struct atomic_flag f = ATOMIC_FLAG_INIT;
	atomic_flag_clear(&f);
	_Bool b1 = atomic_flag_test_and_set(&f);
	assert(b1 == 0);
	_Bool b2 = atomic_flag_test_and_set(&f);
	assert(b2 == 1);
#endif
	return 0;
}
