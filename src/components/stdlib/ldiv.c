
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: ldiv
//----------------------------------------------------------------------------*/
ldiv_t ldiv(long numerator, long denominator) {
	ldiv_t ret;

	assert(denominator);

	ret.quot = numerator / denominator;
	ret.rem = numerator % denominator;
	return ret;
}
