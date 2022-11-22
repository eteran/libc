#undef NDEBUG
#define _ELIBC_SOURCE
#include "test_util.h"
#include <assert.h>
#include <errno.h>
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

static void reverse(char *first, char *last) {
	for (--last; first < last; ++first, --last) {
		char c = *last;
		*last = *first;
		*first = c;
	}
}

/* demo only: does not check for buffer overflow */
static char *itoa(int n, int base, char *buf) {

	div_t dv;
	char *p = buf;

	assert(2 <= base && base <= 16);
	dv.quot = n;

	do {
		dv = div(dv.quot, base);
		*p++ = "0123456789abcdef"[abs(dv.rem)];
	} while (dv.quot);

	if (n < 0) {
		*p++ = '-';
	}

	*p = '\0';
	reverse(buf, p);
	return buf;
}

static void test_div(void) {
	char buf[100];

	itoa(0, 2, buf);
	assert(strcmp(buf, "0") == 0);

	itoa(007, 3, buf);
	assert(strcmp(buf, "21") == 0);

	itoa(12346, 10, buf);
	assert(strcmp(buf, "12346") == 0);

	itoa(-12346, 10, buf);
	assert(strcmp(buf, "-12346") == 0);

	itoa(-42, 2, buf);
	assert(strcmp(buf, "-101010") == 0);

	itoa(INT_MAX, 16, buf);
	assert(strcmp(buf, "7fffffff") == 0);

	itoa(INT_MIN, 16, buf);
	assert(strcmp(buf, "-80000000") == 0);
}

void test_atol(void) {
	assert(atol("1234") == 1234);
	assert(atol("1234junk") == 1234);
	assert(atol("1234") != 123);
}

void test_atoi(void) {
	assert(atoi("1234") == 1234);
	assert(atoi("1234junk") == 1234);
	assert(atoi("1234") != 123);
}

void test_atoll(void) {
	assert(atoll("1234") == 1234);
	assert(atoll("1234junk") == 1234);
	assert(atoll("1234") != 123);
}

void test_wctomb(void) {
	char mb[MB_LEN_MAX];
	int n;

	n = wctomb(mb, L'A');
	assert(n == 1);
	assert(memcmp(mb, "\x41", (size_t)n) == 0);

	n = wctomb(mb, 0xdf);
	assert(n == 2);
	assert(memcmp(mb, "\xc3\x9f", (size_t)n) == 0);

	n = wctomb(mb, 0x1d10b);
	assert(n == 4);
	assert(memcmp(mb, "\xf0\x9d\x84\x8b", (size_t)n) == 0);

	n = wctomb(mb, L'\0');
	assert(n == 1);
	assert(memcmp(mb, "\x00", (size_t)n) == 0);
}

void test_strtol(void) {

	const char *p = "10 200000000000000000000000000000 30 -40";
	char *end;
	long i;

	errno = 0;
	i = strtol(p, &end, 10);
	assert(errno == 0);
	assert(i == 10);
	p = end;

	errno = 0;
	i = strtol(p, &end, 10);
	assert(errno == ERANGE);
	assert(i == LONG_MAX);
	p = end;

	errno = 0;
	i = strtol(p, &end, 10);
	assert(errno == 0);
	assert(i == 30);
	p = end;

	errno = 0;
	i = strtol(p, &end, 10);
	assert(errno == 0);
	assert(i == -40);
	p = end;
}

void test_strtoll(void) {

	const char *p = "10 200000000000000000000000000000 30 -40";
	char *end;
	long long i;

	errno = 0;
	i = strtoll(p, &end, 10);
	assert(errno == 0);
	assert(i == 10);
	p = end;

	errno = 0;
	i = strtoll(p, &end, 10);
	assert(errno == ERANGE);
	assert(i == LLONG_MAX);
	p = end;

	errno = 0;
	i = strtoll(p, &end, 10);
	assert(errno == 0);
	assert(i == 30);
	p = end;

	errno = 0;
	i = strtoll(p, &end, 10);
	assert(errno == 0);
	assert(i == -40);
	p = end;
}

void test_strtoul(void) {
	const char *p = "10 200000000000000000000000000000 30 40";
	char *end;
	unsigned long i;

	errno = 0;
	i = strtoul(p, &end, 10);
	assert(errno == 0);
	assert(i == 10);
	p = end;

	errno = 0;
	i = strtoul(p, &end, 10);
	assert(errno == ERANGE);
	assert(i == ULONG_MAX);
	p = end;

	errno = 0;
	i = strtoul(p, &end, 10);
	assert(errno == 0);
	assert(i == 30);
	p = end;

	errno = 0;
	i = strtoul(p, &end, 10);
	assert(errno == 0);
	assert(i == 40);
	p = end;
}

void test_strtoull(void) {
	const char *p = "10 200000000000000000000000000000 30 40";
	char *end;
	unsigned long i;

	errno = 0;
	i = strtoull(p, &end, 10);
	assert(errno == 0);
	assert(i == 10);
	p = end;

	errno = 0;
	i = strtoull(p, &end, 10);
	assert(errno == ERANGE);
	assert(i == ULLONG_MAX);
	p = end;

	errno = 0;
	i = strtoull(p, &end, 10);
	assert(errno == 0);
	assert(i == 30);
	p = end;

	errno = 0;
	i = strtoull(p, &end, 10);
	assert(errno == 0);
	assert(i == 40);
	p = end;
}

void test_mblen(void) {
	/* "zß水🍌" */
	const char *str = "\x7A\xC3\x9F\xE6\xB0\xB4\xF0\x9F\x8D\x8C";
	const char *ptr = str;
	size_t result = 0;
	const char *end = ptr + strlen(ptr);

	/* reset the conversion state */
	mblen(NULL, 0);

	while (ptr < end) {
		const int next = mblen(ptr, (size_t)(end - ptr));
		if (next == -1) {
			assert(0 && "unexpected failure in mblen");
			break;
		}
		ptr += next;
		++result;
	}

	assert(result == 4);
	assert(strlen(str) == 10);
}

void test_wcstombs(void) {
	/* 4 wide characters */
	const wchar_t src[] = {0x7a, 0xdf, 0x6c34, 0x1f34c, L'\0'};

	/* they occupy 10 bytes in UTF-8 */
	char dst[11];

	const size_t result = wcstombs(dst, src, sizeof dst);
	assert(result == 10);
	assert(memcmp(dst, "\x7A\xC3\x9F\xE6\xB0\xB4\xF0\x9F\x8D\x8C", result) == 0);
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
	assert(MB_CUR_MAX == 4);

	test_abs();
	test_atof();
	test_atoi();
	test_atol();
	test_atoll();
	test_bsearch();
	test_div();
	test_mblen();
	test_mbstowcs();
	test_qsort();
	test_strtol();
	test_strtoll();
	test_strtoul();
	test_strtoull();
	test_wcstombs();

	return 0;
}

/*
#include "c/abort.h"
#include "c/atexit.h"
#include "c/calloc.h"
#include "c/exit.h"
#include "c/free.h"
#include "c/getenv.h"
#include "c/ldiv.h"
#include "c/malloc.h"
#include "c/mbstowcs.h"
#include "c/mbtowc.h"
#include "c/rand.h"
#include "c/realloc.h"
#include "c/srand.h"
#include "c/strtod.h"
#include "c/system.h"

#if defined(_HAS_C99) || defined(_HAS_CXX11) || defined(_ELIBC_SOURCE)
#include "c/_Exit.h"
#include "c/lldiv.h"
#include "c/strtof.h"
#include "c/strtold.h"
#endif
*/
