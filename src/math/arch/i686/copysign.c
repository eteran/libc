
#define _ELIBC_SOURCE
#define __STDC_CONSTANT_MACROS
#include <math.h>
#include <stdint.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_copysign
// Note: assumes IEEE floats
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE static double __elibc_copysign(double x, double y) {

	union double_bits {
		double f_value;
		uint64_t i_value;
	};

	union double_bits x1;
	union double_bits y1;
	union double_bits r;

	/* we currently assume 64-bit doubles */
	_Static_assert(sizeof(double) == sizeof(uint64_t), "Size of double must be 64-bits");

	x1.f_value = x;
	y1.f_value = y;

	r.i_value =
		(y1.i_value & UINT64_C(0x8000000000000000)) | (x1.i_value & UINT64_C(0x7fffffffffffffff));

	return r.f_value;
}

/*------------------------------------------------------------------------------
// Name: copysign
//----------------------------------------------------------------------------*/
double copysign(double x, double y) {
	return __elibc_copysign(x, y);
}

#endif
