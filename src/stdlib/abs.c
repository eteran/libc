
#define __ELIBC_SOURCE
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: abs
//----------------------------------------------------------------------------*/
int abs(int j) {
	assert(j != INT_MIN);
	return (j >= 0) ? j : -j;
}
