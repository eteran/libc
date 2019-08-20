
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

/*------------------------------------------------------------------------------
// Name: labs
//----------------------------------------------------------------------------*/
long int labs(long int j) {
	assert(j != LONG_MIN);
	return (j >= 0) ? j : -j;
}
