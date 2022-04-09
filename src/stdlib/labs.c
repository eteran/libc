
#define _ELIBC_SOURCE
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: labs
//----------------------------------------------------------------------------*/
long int labs(long int j) {
	assert(j != LONG_MIN);
	return (j >= 0) ? j : -j;
}
