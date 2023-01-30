#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>
#include <tgmath.h>

void test_float() {
	float n = sin(123.4f);
	printf("%f\n", n);
}

void test_double() {
	double n = sin(123.4);
	printf("%f\n", n);
}

int main(void) {
	test_float();
	test_double();
	return 0;
}
