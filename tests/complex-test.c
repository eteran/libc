#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <complex.h>

static void test_basic_arithmetic(void) {
#ifdef _HAS_C99
#if 0
	double complex z1 = 1.0 + 2.0 * I;
	double complex z2 = 3.0 - 4.0 * I;

	// Addition
	double complex sum = z1 + z2;
	assert(creal(sum) == 4.0);
	assert(cimag(sum) == -2.0);

	// Subtraction
	double complex diff = z1 - z2;
	assert(creal(diff) == -2.0);
	assert(cimag(diff) == 6.0);

	// Multiplication
	double complex prod = z1 * z2;
	assert(creal(prod) == 11.0);
	assert(cimag(prod) == 2.0);

	// Division
	double complex quot = z1 / z2;
	assert(fabs(creal(quot) - (-0.2)) < 1e-9);
	assert(fabs(cimag(quot) - (0.4)) < 1e-9);
#endif
#endif
}

static void test_properties(void) {
#ifdef _HAS_C11
#if 0
	double complex z3 = 5.0 + 12.0 * I;

	// Real and imaginary parts
	assert(creal(z3) == 5.0);
	assert(cimag(z3) == 12.0);

	// Conjugate
	double complex conj_z3 = conj(z3);
	assert(creal(conj_z3) == 5.0);
	assert(cimag(conj_z3) == -12.0);

	double magnitude = cabs(z3);
	assert(fabs(magnitude - 13.0) < 1e-9);

	double phase = carg(z3);
	assert(fabs(phase - atan2(12.0, 5.0)) < 1e-9);
#endif
#endif
}

int main(void) {
	test_basic_arithmetic();
	test_properties();
	return 0;
}
