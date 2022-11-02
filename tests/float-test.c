/* 100% Coverage */

#undef NDEBUG
#define _ELIBC_SOURCE
#include "test_util.h"
#include <assert.h>
#include <float.h>

int main(void) {
	_Static_assert(IS_CONSTANT(DBL_DIG), "");
	_Static_assert(IS_CONSTANT(DBL_EPSILON), "");
	_Static_assert(IS_CONSTANT(DBL_MANT_DIG), "");
	_Static_assert(IS_CONSTANT(DBL_MAX), "");
	_Static_assert(IS_CONSTANT(DBL_MAX_10_EXP), "");
	_Static_assert(IS_CONSTANT(DBL_MAX_EXP), "");
	_Static_assert(IS_CONSTANT(DBL_MIN), "");
	_Static_assert(IS_CONSTANT(DBL_MIN_10_EXP), "");
	_Static_assert(IS_CONSTANT(DBL_MIN_EXP), "");
	_Static_assert(IS_CONSTANT(FLT_DIG), "");
	_Static_assert(IS_CONSTANT(FLT_EPSILON), "");
	_Static_assert(IS_CONSTANT(FLT_MANT_DIG), "");
	_Static_assert(IS_CONSTANT(FLT_MAX), "");
	_Static_assert(IS_CONSTANT(FLT_MAX_10_EXP), "");
	_Static_assert(IS_CONSTANT(FLT_MAX_EXP), "");
	_Static_assert(IS_CONSTANT(FLT_MIN), "");
	_Static_assert(IS_CONSTANT(FLT_MIN_10_EXP), "");
	_Static_assert(IS_CONSTANT(FLT_MIN_EXP), "");
	_Static_assert(IS_CONSTANT(FLT_RADIX), "");
	_Static_assert(IS_CONSTANT(FLT_ROUNDS), "");
	_Static_assert(IS_CONSTANT(LDBL_DIG), "");
	_Static_assert(IS_CONSTANT(LDBL_EPSILON), "");
	_Static_assert(IS_CONSTANT(LDBL_MANT_DIG), "");
	_Static_assert(IS_CONSTANT(LDBL_MAX), "");
	_Static_assert(IS_CONSTANT(LDBL_MAX_10_EXP), "");
	_Static_assert(IS_CONSTANT(LDBL_MAX_EXP), "");
	_Static_assert(IS_CONSTANT(LDBL_MIN), "");
	_Static_assert(IS_CONSTANT(LDBL_MIN_10_EXP), "");
	_Static_assert(IS_CONSTANT(LDBL_MIN_EXP), "");

#ifdef _HAS_C99
	_Static_assert(IS_CONSTANT(DECIMAL_DIG), "");
	_Static_assert(IS_CONSTANT(FLT_EVAL_METHOD), "");
#endif

#ifdef _HAS_C11
#if 0 /* TODO(eteran): implement these */
	_Static_assert(IS_CONSTANT(FLT_HAS_SUBNORM), "");
	_Static_assert(IS_CONSTANT(DBL_HAS_SUBNORM), "");
	_Static_assert(IS_CONSTANT(LDBL_HAS_SUBNORM), "");
	_Static_assert(IS_CONSTANT(FLT_DECIMAL_DIG), "");
	_Static_assert(IS_CONSTANT(DBL_DECIMAL_DIG), "");
	_Static_assert(IS_CONSTANT(LDBL_DECIMAL_DIG), "");
	_Static_assert(IS_CONSTANT(FLT_TRUE_MIN), "");
	_Static_assert(IS_CONSTANT(DBL_TRUE_MIN), "");
	_Static_assert(IS_CONSTANT(LDBL_TRUE_MIN), "");
#endif
#endif
	return 0;
}
