/* 100% Coverage */

#undef NDEBUG
#define _ELIBC_SOURCE
#include "test_util.h"
#include <assert.h>
#include <limits.h>

int main(void) {
	_Static_assert(IS_CONSTANT(CHAR_BIT), "");
	_Static_assert(IS_CONSTANT(CHAR_MAX), "");
	_Static_assert(IS_CONSTANT(CHAR_MIN), "");
	_Static_assert(IS_CONSTANT(INT_MAX), "");
	_Static_assert(IS_CONSTANT(INT_MIN), "");
	_Static_assert(IS_CONSTANT(LLONG_MAX), "");
	_Static_assert(IS_CONSTANT(LLONG_MIN), "");
	_Static_assert(IS_CONSTANT(LONG_MAX), "");
	_Static_assert(IS_CONSTANT(LONG_MIN), "");
	_Static_assert(IS_CONSTANT(MB_LEN_MAX), "");
	_Static_assert(IS_CONSTANT(SCHAR_MAX), "");
	_Static_assert(IS_CONSTANT(SCHAR_MIN), "");
	_Static_assert(IS_CONSTANT(SHRT_MAX), "");
	_Static_assert(IS_CONSTANT(SHRT_MIN), "");
	_Static_assert(IS_CONSTANT(UCHAR_MAX), "");
	_Static_assert(IS_CONSTANT(UINT_MAX), "");
	_Static_assert(IS_CONSTANT(ULLONG_MAX), "");
	_Static_assert(IS_CONSTANT(ULONG_MAX), "");
	_Static_assert(IS_CONSTANT(USHRT_MAX), "");

	return 0;
}
