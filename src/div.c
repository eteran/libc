
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: div
//----------------------------------------------------------------------------*/
div_t div(int numerator, int denominator) {
	div_t ret;

	assert(denominator);

	ret.quot = numerator / denominator;
	ret.rem  = numerator % denominator;
	return ret;
}
