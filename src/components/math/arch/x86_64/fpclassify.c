
#define _ELIBC_SOURCE
#define __STDC_CONSTANT_MACROS
#include <math.h>
#include <stdint.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_copysign
// Note: assumes IEEE floats
//----------------------------------------------------------------------------*/
int __elibc_fpclassify(double x) {

	union double_bits {
		double f_value;
		uint64_t i_value;
	};

	uint32_t exp;
	union double_bits u;

	_Static_assert(sizeof(double) == sizeof(uint64_t), "Size of double must be 64-bits");

	u.f_value = x;

	exp = (uint32_t)((u.i_value & UINT64_C(0x7fffffffffffffff)) >> 52);

	if (exp == 0) {
		if (u.i_value & UINT64_C(0x000fffffffffffff)) {
			return FP_SUBNORMAL;
		}

		return FP_ZERO;
	}

	if (exp == 0x7ff) {
		if (u.i_value & UINT64_C(0x000fffffffffffff)) {
			return FP_NAN;
		}

		return FP_INFINITE;
	}

	return FP_NORMAL;
}

#endif
