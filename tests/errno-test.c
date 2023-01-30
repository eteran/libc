#undef NDEBUG
#define _ELIBC_SOURCE
#include "test_util.h"
#include <assert.h>
#include <errno.h>
#include <math.h>

#ifndef errno
#error "errno is not defined"
#endif

static void test_assignment(void) {
	errno = ENOMEM;
	assert(errno == ENOMEM);
}

static void test_domain_error(void) {
	/* just do something that should set errno */
	double r = sqrt(-10.0);
	assert(isnan(r));
	assert(errno == EDOM);
}

int main(void) {

#ifdef _HAS_C11
	TYPE_DEFINED(errno_t);
#endif

	test_assignment();
	test_domain_error();
	return 0;
}
