
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#define C 12345
#define A 1103515245

/*------------------------------------------------------------------------------
// Name: rand
//----------------------------------------------------------------------------*/
int rand(void) {
	return rand_r(__elibc_rand_next());
}

/*------------------------------------------------------------------------------
// Name: rand_r
//----------------------------------------------------------------------------*/
int rand_r(unsigned int *seedp) {

	assert(seedp);
	{
		unsigned int next = *seedp;
		int result;

		next *= A;
		next += C;
		result = (next / 65536) & 0x7ff;

		next *= A;
		next += C;
		result <<= 10;
		result ^=  (next / 65536) & 0x3ff;

		next *= A;
		next += C;
		result <<= 10;
		result ^= (next / 65536) & 0x3ff;

		*seedp = next;

		return result & RAND_MAX;
	}
}

/*------------------------------------------------------------------------------
// Name: __elibc_rand_next
//----------------------------------------------------------------------------*/
unsigned int *__elibc_rand_next(void) {
	static _Thread_local unsigned int _next = 1;
	return &_next;
}
