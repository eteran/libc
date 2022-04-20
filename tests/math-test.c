#undef NDEBUG
#define _ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>
#include <float.h>
#include <math.h>
#include <fenv.h>

#define EPSILON 0.000001f

static int float_compare(float lhs, float rhs) {
	return fabs(lhs - rhs) < EPSILON;
}

static void test_fabs(void) {
	assert(fabs(+3.0) == 3.0);
	assert(fabs(-3.0) == 3.0);
	assert(fabs(-0) == 0);

	assert(fabs(-INFINITY) == INFINITY);

	assert(fabsf(+3.0f) == 3.0f);
	assert(fabsf(-3.0f) == 3.0f);
	assert(fabsf(-0) == 0);

	assert(fabsl(+3.0L) == 3.0L);
	assert(fabsl(-3.0L) == 3.0L);
	assert(fabsl(-0) == 0);
}

static void test_cos(void) {
	/* typical usage */
	assert(float_compare(cos(M_PI / 3.0), 0.500000));
	assert(float_compare(cos(M_PI / 2.0), 0.000000));
	assert(float_compare(cos(-3.0 * M_PI / 4), -0.707107));
	/* special values */
	assert(float_compare(cos(-0.0), 1.0));
	assert(float_compare(cos(+0.0), 1.0));

	/* error handling */
	feclearexcept(FE_ALL_EXCEPT);
	assert(!fetestexcept(FE_INVALID));
	assert(isnan(cos(INFINITY)));
	assert(fetestexcept(FE_INVALID));
}

static void test_sin(void) {
	/* typical usage */
	assert(float_compare(sin(M_PI / 6.0), 0.500000));
	assert(float_compare(sin(M_PI / 2.0), 1.000000));
	assert(float_compare(sin(-3.0 * M_PI / 4), -0.707107));
	/* special values */
	assert(float_compare(sin(-0.0), 0.0));
	assert(float_compare(sin(+0.0), 0.0));

	/* error handling */
	feclearexcept(FE_ALL_EXCEPT);
	assert(!fetestexcept(FE_INVALID));
	assert(isnan(sin(INFINITY)));
	assert(fetestexcept(FE_INVALID));
}

static void test_tan(void) {
	/* typical usage */
	assert(float_compare(tan(1.0 * M_PI / 4.0), +1.000000));
	assert(float_compare(tan(3.0 * M_PI / 4.0), -1.000000));
	assert(float_compare(tan(5.0 * M_PI / 4.0), +1.000000));
	assert(float_compare(tan(7.0 * M_PI / 4.0), -1.000000));
	/* special values */
	assert(float_compare(tan(-0.0), 0.0));
	assert(float_compare(tan(+0.0), 0.0));

	/* error handling */
	feclearexcept(FE_ALL_EXCEPT);
	assert(!fetestexcept(FE_INVALID));
	assert(isnan(tan(INFINITY)));
	assert(fetestexcept(FE_INVALID));
}

static void test_floor(void) {
    double d;
	d = floor(-INFINITY);
	assert(isinf(d) && d < 0.0);

	assert(float_compare(floor(2.7), +2.0));
    assert(float_compare(floor(-2.7), -3.0));
    assert(float_compare(floor(-0.0), -0.0));
}

static void test_ceil(void) {
	double d;
	d = ceil(-INFINITY);
	assert(isinf(d) && d < 0.0);

	assert(float_compare(ceil(2.4), +3.0));
    assert(float_compare(ceil(-2.4), -2.0));
    assert(float_compare(ceil(-0.0), -0.0));
}

#if 0
#include "c/acos.h"
#include "c/asin.h"
#include "c/atan.h"
#include "c/atan2.h"
#include "c/cosh.h"
#include "c/exp.h"
#include "c/fmod.h"
#include "c/frexp.h"
#include "c/ldexp.h"
#include "c/log.h"
#include "c/log10.h"
#include "c/modf.h"
#include "c/pow.h"
#include "c/sinh.h"
#include "c/sqrt.h"
#include "c/tanh.h"
#endif

int main(void) {
	test_fabs();
	test_cos();
	test_sin();
	test_tan();
	test_floor();
	test_ceil();
	return 0;
}
