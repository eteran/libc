#undef NDEBUG
#define _ELIBC_SOURCE
#include "test_util.h"
#include <assert.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EPSILON 0.000001

static int float_compare(double lhs, double rhs) {
	return fabs(lhs - rhs) < EPSILON;
}
struct data {
	int nr;
	char const *value;
};

static int data_cmp(void const *lhs, void const *rhs) {
	struct data const *const l = lhs;
	struct data const *const r = rhs;

	if (l->nr < r->nr) {
		return -1;
	} else if (l->nr > r->nr) {
		return 1;
	} else {
		return 0;
	}
}

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

static void test_bsearch(void) {

	struct data dat[] = {{1, "Foo"}, {2, "Bar"}, {3, "Hello"}, {4, "World"}};
	const size_t size = sizeof(dat) / sizeof(*dat);

	{
		struct data key = {3, NULL};
		struct data const *res = bsearch(&key, dat, size, sizeof(struct data), data_cmp);
		assert(res->nr == 3 && strcmp(res->value, "Hello") == 0);
	}

	{
		struct data key = {30, NULL};
		struct data const *res = bsearch(&key, dat, size, sizeof(struct data), data_cmp);
		assert(res == NULL);
	}
}

static void test_atof(void) {
	/* TODO(eteran): some sort of epsilon comparison */

	assert(float_compare(atof("  -0.0000000123junk"), -1.23e-08));
	assert(float_compare(atof("0.012"), 0.012));
	assert(float_compare(atof("15e16"), 1.5e+17));
#if 0 /* hex floats not supported yet */
	assert(float_compare(atof("-0x1afp-2"), -107.75));
#endif
	assert(isinf(atof("inF")));
	assert(isnan(atof("Nan")));
	assert(atof("0.0") == 0.0);
	assert(atof("junk") == 0.0);     /* no conversion can be performed */
	assert(isinf(atof("1.0e+309"))); /* UB: out of range of double */
}

static void test_mbstowcs(void) {
	/*    u8"z\u00df\u6c34\U0001F34C" */
	/* or u8"zß水🍌" */
	const char input[] = "\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9f\x8d\x8c";
	wchar_t output[sizeof(input)] = L"";
	size_t rc = mbstowcs(output, input, sizeof(output));

	assert(rc == 4);
	assert(output[0] == 0x7a);
	assert(output[1] == 0xdf);
	assert(output[2] == 0x6c34);
	assert(output[3] == 0x1f34c);
	assert(output[4] == L'\0');

	assert(mbstowcs(NULL, input, 1024) == 4);
}

int main(void) {

	/* TODO support close enough locales, such as "en_US.utf8" */
	setlocale(LC_ALL, "en_US.UTF-8");

	_Static_assert(IS_CONSTANT(EXIT_FAILURE), "");
	_Static_assert(IS_CONSTANT(EXIT_SUCCESS), "");
	_Static_assert(IS_CONSTANT(RAND_MAX), "");

	TYPE_DEFINED(div_t);
	TYPE_DEFINED(ldiv_t);
	TYPE_DEFINED(lldiv_t);
	TYPE_DEFINED(size_t);
	TYPE_DEFINED(wchar_t);

	_Static_assert(IS_SAME_TYPE(NULL, void *), "");
	_Static_assert(IS_SAME_TYPE(MB_CUR_MAX, size_t), "");

	test_mbstowcs();
	test_abs();
	test_qsort();
	test_bsearch();
	test_atof();

	return 0;
}

/*
#include "c/abort.h"
#include "c/atexit.h"
#include "c/atoi.h"
#include "c/atol.h"
#include "c/calloc.h"
#include "c/div.h"
#include "c/exit.h"
#include "c/free.h"
#include "c/getenv.h"
#include "c/labs.h"
#include "c/ldiv.h"
#include "c/malloc.h"
#include "c/mblen.h"
#include "c/mbstowcs.h"
#include "c/mbtowc.h"
#include "c/rand.h"
#include "c/realloc.h"
#include "c/srand.h"
#include "c/strtod.h"
#include "c/strtol.h"
#include "c/strtoul.h"
#include "c/system.h"
#include "c/wcstombs.h"

#if defined(_HAS_C99) || defined(_HAS_CXX11) || defined(_ELIBC_SOURCE)
#include "c/_Exit.h"
#include "c/atoll.h"
#include "c/llabs.h"
#include "c/lldiv.h"
#include "c/strtof.h"
#include "c/strtold.h"
#include "c/strtoll.h"
#include "c/strtoull.h"
#endif

#if defined(_HAS_C99) || defined(_HAS_CXX89) || defined(_ELIBC_SOURCE)
#include "c/wctomb.h"
#endif
*/
