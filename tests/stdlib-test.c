#undef NDEBUG
#define _ELIBC_SOURCE
#include "test_util.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static void test_abs(void) {
	assert(abs(100) == 100);
	assert(abs(-100) == 100);
	assert(labs(100L) == 100L);
	assert(labs(-100L) == 100L);
	assert(llabs(100LL) == 100LL);
	assert(llabs(-100LL) == 100LL);
}

static int compare(const void *a, const void *b) {
	int arg1 = *(const int *)(a);
	int arg2 = *(const int *)(b);

	if (arg1 < arg2)
		return -1;
	if (arg1 > arg2)
		return 1;
	return 0;
}

static void test_qsort(void) {

	size_t i;
	int last = INT_MIN;
	int a[] = {-2, 99, 0, -743, 2, INT_MIN, 4};

	const size_t size = sizeof(a) / sizeof(*a);

	qsort(a, size, sizeof(*a), compare);

	for (i = 0; i < sizeof(a) / sizeof(*a); ++i) {
		assert(a[i] >= last);
		last = a[i];
	}
}

int main(void) {

	_Static_assert(IS_CONSTANT(EXIT_FAILURE), "");
	_Static_assert(IS_CONSTANT(EXIT_SUCCESS), "");
	_Static_assert(IS_CONSTANT(RAND_MAX), "");

	TYPE_DEFINED(div_t)
	TYPE_DEFINED(ldiv_t)
	TYPE_DEFINED(lldiv_t)
	TYPE_DEFINED(size_t)
	TYPE_DEFINED(wchar_t)

	_Static_assert(IS_SAME_TYPE(NULL, void *), "");
	_Static_assert(IS_SAME_TYPE(MB_CUR_MAX, size_t), "");

	test_abs();
	test_qsort();
	return 0;
}
