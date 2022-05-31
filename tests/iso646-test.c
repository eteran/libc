/* 100% Coverage */

#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <iso646.h>

static void test_assignments(void) {
	unsigned char x = 0x55;

	x and_eq 0x05;
	assert(x == 0x05);

	x or_eq 0xa0;
	assert(x == 0xa5);

	x xor_eq 0xf0;
	assert(x == 0x55);
}

int main(void) {

	_Static_assert((1 and 1), "");
	_Static_assert(not(1 and 0), "");
	_Static_assert(not(1 and 0), "");
	_Static_assert(not(0 and 0), "");

	_Static_assert((1 or 0), "");
	_Static_assert((0 or 1), "");
	_Static_assert((1 or 1), "");
	_Static_assert(not(0 or 0), "");

	_Static_assert(not(1 xor 1), "");
	_Static_assert((1 xor 0), "");
	_Static_assert((1 xor 0), "");
	_Static_assert(not(0 xor 0), "");

	_Static_assert((compl 0x5a5a5a5au) == 0xa5a5a5a5u, "");

	_Static_assert((1 bitand 1) == 1, "");
	_Static_assert((1 bitand 0) == 0, "");
	_Static_assert((1 bitand 0) == 0, "");
	_Static_assert((0 bitand 0) == 0, "");

	_Static_assert((1 bitor 0) == 1, "");
	_Static_assert((0 bitor 1) == 1, "");
	_Static_assert((1 bitor 1) == 1, "");
	_Static_assert((0 bitor 0) == 0, "");

	_Static_assert((0 not_eq 1), "");
	_Static_assert(not(1 not_eq 1), "");

	test_assignments();
	return 0;
}
