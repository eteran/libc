
#define _ELIBC_SOURCE
#define __STDC_CONSTANT_MACROS
#include <math.h>
#include <stdint.h>

#ifdef _HAS_FPU

/**
 * @brief Copy the sign of one floating point number to another
 *
 * @param x the floating point number to copy the sign from
 * @param y the floating point number to copy the sign to
 * @return the floating point number with the sign of x
 * @note Assumes IEEE floats
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE _CONST static float __elibc_copysignf(float x, float y) {

	union float_bits {
		float f_value;
		uint32_t i_value;
	};

	union float_bits x1;
	union float_bits y1;
	union float_bits r;

	/* we assume 32-bit floats */
	_Static_assert(sizeof(float) == sizeof(uint32_t), "Size of float must be 32-bits");

	x1.f_value = x;
	y1.f_value = y;

	r.i_value = ((y1.i_value & UINT32_C(0x80000000)) | (x1.i_value & UINT32_C(0x7fffffff)));

	return r.f_value;
}

/**
 * @brief Copy the sign of one floating point number to another
 *
 * @param x the floating point number to copy the sign from
 * @param y the floating point number to copy the sign to
 * @return the floating point number with the sign of x
 */
float copysignf(float x, float y) {
	return __elibc_copysignf(x, y);
}

#endif
