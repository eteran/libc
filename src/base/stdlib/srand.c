
#define _ELIBC_SOURCE
#include <stdlib.h>

/**
 * @brief Set the seed for the random number generator
 *
 * @param seed
 */
void srand(unsigned int seed) {
	*__elibc_rand_next() = seed;
}
