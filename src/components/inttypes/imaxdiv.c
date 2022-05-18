
#define _ELIBC_SOURCE
#include <assert.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>

/*------------------------------------------------------------------------------
// Name: imaxdiv
//----------------------------------------------------------------------------*/
imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator) {
	imaxdiv_t ret;

	assert(denominator != 0);

	ret.quot = numerator / denominator;
	ret.rem = numerator % denominator;
	return ret;
}
