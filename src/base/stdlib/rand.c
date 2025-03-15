
#define _ELIBC_SOURCE
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

#define C 12345
#define A 1103515245

/**
 * @brief Generate a random number
 *
 * @return a random number between 0 and RAND_MAX
 */
int rand(void) {
	return rand_r(__elibc_rand_next());
}

/**
 * @brief Generate a random number using a seed
 *
 * @param seedp a pointer to the seed
 * @return a random number between 0 and RAND_MAX
 */
int rand_r(unsigned int *seedp) {

	assert(seedp);
	{
		unsigned int next = *seedp;
		unsigned int result;

		next *= A;
		next += C;
		result = (next / 65536) & 0x7ff;

		next *= A;
		next += C;
		result <<= 10;
		result ^= (next / 65536) & 0x3ff;

		next *= A;
		next += C;
		result <<= 10;
		result ^= (next / 65536) & 0x3ff;

		*seedp = next;

		return (int)(result & RAND_MAX);
	}
}

/**
 * @brief Get the thread-local random number generator state
 *
 * @return a pointer to the thread-local random number generator state
 */
unsigned int *__elibc_rand_next(void) {
	static _Thread_local unsigned int next = 1;
	return &next;
}
