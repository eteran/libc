#undef NDEBUG
#define _ELIBC_SOURCE
#include "test_util.h"
#include <assert.h>
#include <inttypes.h>
#include <limits.h>

static void test_maxabs(void) {
	uintmax_t i = UINTMAX_MAX;
	assert(i == UINTMAX_MAX);

	assert(imaxabs(-100) == 100);
	assert(imaxabs(100) == 100);
	assert(imaxabs(LLONG_MIN + 2) == 9223372036854775806);
}

static void test_imaxdiv(void) {
	intmax_t i  = 57;
	imaxdiv_t r = imaxdiv(i, 10);
	assert(r.quot == 5);
	assert(r.rem == 7);
}

static void test_strtoimax(void) {
}

static void test_strtoumax(void) {
}

static void test_wcstoimax(void) {
}

static void test_wcstoumax(void) {
}

int main(void) {

	TYPE_DEFINED(uintmax_t);
	test_maxabs();
	test_imaxdiv();
	test_strtoimax();
	test_strtoumax();
	test_wcstoimax();
	test_wcstoumax();
	return 0;
}
