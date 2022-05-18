
#define _ELIBC_SOURCE
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: srand
//----------------------------------------------------------------------------*/
void srand(unsigned int seed) {
	*__elibc_rand_next() = seed;
}
