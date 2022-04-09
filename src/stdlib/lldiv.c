
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: lldiv
//----------------------------------------------------------------------------*/
lldiv_t lldiv(long long numerator, long long denominator) {
	lldiv_t ret;

	assert(denominator);

	ret.quot = numerator / denominator;
	ret.rem = numerator % denominator;
	return ret;
}
