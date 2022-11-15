#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

#define EPSILON 0.000001

static int float_compare(double lhs, double rhs) {
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
	assert(float_compare(cos(-3.0 * M_PI / 4.0), -0.707107));
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
	assert(float_compare(sin(-3.0 * M_PI / 4.0), -0.707107));
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

static void test_isnormal(void) {
	assert(!isnormal(NAN));
	assert(!isnormal(INFINITY));
	assert(!isnormal(0.0));
	assert(!isnormal(DBL_MIN / 2.0));
	assert(isnormal(1.0));
}

static void test_isfinite(void) {
	assert(!isfinite(NAN));
	assert(!isfinite(INFINITY));
	assert(isfinite(0.0));
	assert(isfinite(DBL_MIN / 2.0));
	assert(isfinite(1.0));
	assert(!isfinite(exp(800)));
}

static void test_isnan(void) {
	assert(isnan(NAN));
	assert(!isnan(INFINITY));
	assert(!isnan(0.0));
	assert(!isnan(DBL_MIN / 2.0));
	assert(isnan(0.0 / 0.0));
	assert(isnan(INFINITY - INFINITY));
}

static void test_isinf(void) {
	assert(!isinf(NAN));
	assert(isinf(INFINITY));
	assert(!isinf(0.0));
	assert(!isinf(DBL_MIN / 2.0));
	assert(!isinf(1.0));
	assert(isinf(exp(800)));
}

static void test_fpclassify(void) {
	assert(fpclassify(1.0 / 0.0) == FP_INFINITE);
	assert(fpclassify(0.0 / 0.0) == FP_NAN);
	assert(fpclassify(DBL_MIN / 2) == FP_SUBNORMAL);
	assert(fpclassify(-0.0) == FP_ZERO);
	assert(fpclassify(1.0) == FP_NORMAL);
}

static void test_copysign(void) {
	double d;
	assert(copysign(1.0, +2.0) == +1.0);
	assert(copysign(1.0, -2.0) == -1.0);

	d = copysign(INFINITY, -2.0);
	assert(signbit(d));
	assert(isinf(d));
	assert(d == -INFINITY);

	d = copysign(NAN, -2.0);
	assert(signbit(d));
	assert(isnan(d));
}

static void test_exp2(void) {
	assert(float_compare(exp2(5), 32.000000));
	assert(float_compare(exp2(0.5), 1.414214));
	assert(float_compare(exp2(-4), 0.062500));

	/* special values */
	assert(float_compare(exp2(-0.9), 0.535887));
	assert(float_compare(exp2(-INFINITY), 0.0));

#if 0
	// error handling
	errno = 0;
	feclearexcept(FE_ALL_EXCEPT);
	printf("exp2(1024) = %f\n", exp2(1024));
	if (errno == ERANGE)
		perror("    errno == ERANGE");
	if (fetestexcept(FE_OVERFLOW))
		puts("    FE_OVERFLOW raised");
#endif
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
	printf("long double size: %lu\n", sizeof(long double));
	printf("double size: %lu\n", sizeof(double));
	printf("float size: %lu\n", sizeof(float));

	test_ceil();
	test_copysign();
	test_cos();
	test_fabs();
	test_floor();
	test_fpclassify();
	test_isfinite();
	test_isinf();
	test_isnan();
	test_isnormal();
	test_sin();
	test_tan();
	test_exp2();

	return 0;
}
