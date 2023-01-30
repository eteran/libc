#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>
#include <tgmath.h>

static void test_float() {
	float n = sin(2.0f);
	printf("%f\n", n);
}

static void test_double() {
	double n = sin(123.4);
	printf("%f\n", n);
}

int main(void) {
	test_float();
	test_double();
	return 0;
}
