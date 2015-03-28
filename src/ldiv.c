
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: ldiv
//----------------------------------------------------------------------------*/
ldiv_t ldiv(long numerator, long denominator) {
	ldiv_t ret;
	
	assert(denominator);
	
	ret.quot = numerator / denominator;
	ret.rem  = numerator % denominator;
	return ret;
}
