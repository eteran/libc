
#define __ELIBC_SOURCE
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: llabs
//----------------------------------------------------------------------------*/
long long int llabs(long long int j) {
	assert(j != LLONG_MIN);
	return (j >= 0) ? j : -j;
}
