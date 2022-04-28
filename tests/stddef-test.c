/* 100% Coverage */
#undef NDEBUG
#define _ELIBC_SOURCE
#include "test_util.h"
#include <assert.h>
#include <stddef.h>

struct S {
	char m0;
	double m1;
	short m2;
	char m3;
};

static void test_offsetof(void) {
	assert(offsetof(struct S, m0) == 0);
	assert(offsetof(struct S, m1) == 8);
	assert(offsetof(struct S, m2) == 16);
	assert(offsetof(struct S, m3) == 18);
}

int main(void) {
	TYPE_DEFNIED(ptrdiff_t)
	TYPE_DEFNIED(size_t)
	TYPE_DEFNIED(wchar_t)
	TYPE_DEFNIED(max_align_t)
	_Static_assert(IS_SAME_TYPE(NULL, void *), "");

	test_offsetof();
	return 0;
}
