
#define __ELIBC_SOURCE
#include <stddef.h>
#include <inttypes.h>
#include <stdint.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: imaxdiv
//----------------------------------------------------------------------------*/
imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator) {
	imaxdiv_t ret = { 0, 0 };
	
	assert(denominator != 0);
	
	ret.quot = numerator / denominator;
	ret.rem  = numerator % denominator;
	return ret;
}
