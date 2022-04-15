#undef NDEBUG
#define _ELIBC_SOURCE /* is nan only exists in C99+ or with _ELIBC_SOURCE defined) */
#include <assert.h>
#include <errno.h>
#include <math.h>

void test_assignment(void) {
	errno = ENOMEM;
	assert(errno == ENOMEM);
}

void test_domain_error(void) {
	/* just do something that should set errno */
	double r = sqrt(-10.0);
	assert(isnan(r));
	assert(errno == EDOM);
}

int main(void) {
	test_assignment();
	test_domain_error();
	return 0;
}